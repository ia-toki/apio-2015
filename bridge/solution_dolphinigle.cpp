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

//zero indexed
class FenwickRangeTree {
 public:
  int n_;
  ll* addum_;
  ll* base_;
  FenwickRangeTree(int n) {
    n_ = n + 1;
    addum_ = new ll[n_ + 10];
    base_ = new ll[n_ + 10];
    FORN(i, n_) addum_[i+1] = base_[i+1] = 0;
  }

  ~FenwickRangeTree() {
    delete[] addum_;
    delete[] base_;
  }

 private:
  void DoAdd_(int pos, ll val) {
    ++pos;
    for (int i = pos; i <= n_; i += (i&-i)) {
      addum_[i] += val;
      base_[i] += -(ll)(pos - (i-(i&-i)) - 1) * val;
    }
  }

  ll DoSum_(int pos) {
    ll res = 0LL;
    ++pos;
    for (int i = pos; i > 0; i -= (i&-i)) {
      res += (pos - (i - (i&-i))) * addum_[i];
      res += base_[i];
    }
    return res;
  }

 public:
  void AddRange(int lb, int ub, ll val) {
    if (lb > ub) return;
    DoAdd_(lb, val);
    DoAdd_(ub+1, -val);
  }
  void Add(int pos, ll val) {
    AddRange(pos, pos, val);
  }
  ll Sum(int lb, int ub) {
    if (lb > ub) return 0LL;
    return DoSum_(ub) - DoSum_(lb-1);
  }
  ll Get(int pos) {
    return DoSum_(pos) - DoSum_(pos-1);
  }
};
// FenwickRangeTree tree(n);
// tree.Add(5, +103);
// tree.AddRange(1, 8, -273);
// tree.Get(4);  // value at position 4
// tree.Sum(2, 7);  // sum of values

const int kMaxN = 120000;

ll values[2][2*kMaxN];
int valueof[2*kMaxN];

#ifdef DOLPHINIGLE_ENV
int main_a() {
#else
int main() {
#endif
  int k, n;
  scanf("%d%d\n", &k, &n);
  ll base = 0LL;
  vector< pair<ll, pair<ll, ll>>> items;
  vector<int> coordinates;
  map<int, int> coormap;
  FORN(i, n) {
    char a, b;
    int f, t;
    scanf("%c %d %c %d\n", &a, &f, &b, &t);
    if (a == b) base += abs(f-t);
    else {
      base += (ll)abs(f-t);
      if (t < f) swap(f, t);
      items.PB(MP(f+t, MP(f, t)));
    }
    coordinates.PB(f);
    coordinates.PB(t);
  }
  sort(ALL(coordinates));
  coordinates.erase(unique(ALL(coordinates)), coordinates.end());
  for (auto i: coordinates) {
    int newidx = SZ(coormap);
    coormap[i] = newidx;
    valueof[newidx] = i;
  }
  int m = SZ(coormap);
  sort(ALL(items));
  FORN(i, 2) {
    FenwickRangeTree baseval(m+2), increment(m+2);
    FORN(j, SZ(items)) {
      int it1 = items[j].B.A;
      int it2 = items[j].B.B;
      int idx1 = coormap[it1];
      int idx2 = coormap[it2];
      baseval.AddRange(0, idx1, it1*2LL);
      baseval.AddRange(idx2, m-1, -it2*2LL);
      increment.AddRange(0, idx1, -2);
      increment.AddRange(idx2, m-1, 2);
      // Ternary search now.
      int ub = m-1;
      int lb = 0;
      while (ub-lb >= 10) {
        int dist = (ub-lb);
        int low = lb + dist / 3;
        int hi = lb + (dist*2)/3;
        ll lowv = baseval.Get(low) + increment.Get(low) * valueof[low];
        ll hiv = baseval.Get(hi) + increment.Get(hi) * valueof[hi];  // AIDS!
        if (lowv == hiv) {
          ub = hi;
          lb = low;
        } else if (lowv < hiv) {
          ub = hi-1;
        } else {
          lb = low+1;
        }
      }
      ll best = (ll)INF * (ll)INF;
      for (int j = lb; j <= ub; ++j) {
        ll v = baseval.Get(j) + increment.Get(j) * valueof[j];  // AIDS!
        MN(best, v);
      }
      values[i][j+1] = best;
    }
    reverse(ALL(items));
  }

  ll best = (ll)INF * (ll)INF;
  if (k == 1) {
    best = values[0][SZ(items)] + base + SZ(items);
  } else {
    FORN(i, SZ(items)+1) {
      MN(best, values[0][i] + values[1][SZ(items)-i]);
    }
    best += base + SZ(items);
  }
  cout << best << endl;

  return 0;
}
