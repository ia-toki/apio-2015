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

const int kMaxDoge2 = 50005;
vector<int> doges[kMaxDoge2];
int ddone[kMaxDoge2];
int vvalues[kMaxDoge2];

#ifdef DOLPHINIGLE_ENV
int main_c() {
#else
int main() {
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  int initial, target;
  FORN(i, m) {
    int building, power;
    scanf("%d %d", &building, &power);
    doges[building].push_back(power);
    if (!i) initial = building;
    if (i == 1) target = building;
  }
  FORN(i, n) vvalues[i] = -1;
  vvalues[initial] = 0;
  while (true) {
    int best = -1;
    for (int j = 0; j < n; ++j) if (vvalues[j] != -1 && !ddone[j]) {
      if (best == -1 || vvalues[best] > vvalues[j]) best = j;
    }
    if (best == -1) {
      cout << -1 << endl;
      break;
    }
    if (best == target) {
      cout << vvalues[best] << endl;
      break;
    }
    ddone[best] = true;
    for (auto doge: doges[best]) {
      for (int i=0, j = best; j >= 0; j -= doge, ++i) {
        if (vvalues[j] == -1 || vvalues[j] > vvalues[best] + i) {
          vvalues[j] = vvalues[best] + i;
        }
      }
      for (int i=0, j = best; j < n; j += doge, ++i) {
        if (vvalues[j] == -1 || vvalues[j] > vvalues[best] + i) {
          vvalues[j] = vvalues[best] + i;
        }
      }
    }
  }
}
