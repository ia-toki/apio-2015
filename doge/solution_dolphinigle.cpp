// Authored by dolphinigle

#include <vector>
#include <list>
#include <map>
#include <set>

#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

#define FORN(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define REP(X,Y,Z) for (int (X) = (Y);(X) < (Z);++(X))

#define SZ(Z) ((int)(Z).size())
#define ALL(W) (W).begin(), (W).end()
#define PB push_back

#define MP make_pair
#define A first
#define B second

#define INF 1023123123
#define EPS 1e-11

#define MX(Z,Y) Z = max((Z),(Y))
#define MN(X,Y) X = min((X),(Y))

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vint;

const int kMaxN = 50005;
const int kMaxSqrtN = 300;
const int kMaxAnswer = 13000000;

vector<int> powers[kMaxN];  // List of doges in a building.
vector<ll> q[kMaxAnswer];
int done[kMaxN][kMaxSqrtN];

int n, m;
ll Encode(int building, int power) {
  assert(power <= kMaxSqrtN);
  return building + power * n;
}

#ifdef DOLPHINIGLE_ENV
int main_a() {
#else
int main() {
#endif
  cin >> n >> m;
  int initial = -1, doge1 = -1;
  FORN(i, m) {
    int building, power;
    cin >> building >> power;
    powers[building].push_back(power);
    if (!i) initial = building;
    if (i == 1) doge1 = building;
  }
  int max_m = (int)sqrt(n);
  // The graph has two kinds of nodes:
  // 1) (building, power) node        printf("%02hX goes in %hu to %02hX\n", (unsigned short int)a, (unsigned short int)d, (unsigned short int)other);
  // 2) (building) node
  // We represent the second type with (building, 0).
  q[0].push_back(1LL * initial);

  int current_answer = 0;
  int best_answer = -1;
  while (current_answer < kMaxAnswer) {
    if (q[current_answer].empty()) {
      ++current_answer;
      continue;
    }
    ll top = q[current_answer].back();
    q[current_answer].pop_back();
    int building = top % n;
    int power = top / n;
    if (done[building][power]) continue;
    done[building][power] = true;

    if (building == doge1) {
      if (best_answer == -1) {
        best_answer = current_answer;
      }
      continue;
    }
    if (!power) {
      // in a building. Transition to every doges in the building that are weak, or make a jump.
      for (int doge : powers[building]) {
        if (doge <= max_m) {
          // go to doge!
          q[current_answer].push_back(Encode(building, doge));
        } else {
          // all possible locations: forward and backwards.
          for (int dir = -1; dir < 2; dir += 2) {
            for (int jumps = 1;;++jumps) {
              int pos = building + doge * dir * jumps;
              if (pos < 0 || pos >= n) break;
              q[current_answer + jumps].push_back(Encode(pos, 0));
            }
          }
        }
      }
    } else {
      // have a power.
      // Transition to building.
      q[current_answer].push_back(Encode(building, 0));
      // Jump front and back.
      int pos = building + power;
      if (pos < n) q[current_answer + 1].push_back(Encode(pos, power));
      pos = building - power;
      if (pos >= 0) q[current_answer + 1].push_back(Encode(pos, power));
    }
  }
  cout << best_answer << endl;
  return 0;
}








