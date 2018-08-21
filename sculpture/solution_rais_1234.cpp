#include <bits/stdc++.h>
using namespace std;

const int N = 2010;

bool f[N][N][2];
bitset<N> adj[N][2];
bitset<N> tmp[2];

int main() {
  ios::sync_with_stdio(0);
  int n, p, q;
  cin >> n >> p >> q;
  vector<int> a(n);
  vector<long long> sum(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum[i] = a[i];
  }
  for (int i = 1; i < n; i++) {
    sum[i] += sum[i - 1];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      adj[i][0][j] = true;
    }
  }
  long long greedy = 0;
  long long mask = 0;
  for (int bit = 39; bit >= 0; bit--) {
    for (int i = 0; i < n; i++) {
      tmp[0].reset();
      tmp[1].reset();
      for (int j = i; j < n; j++) {
        long long cur = sum[j] - (i == 0 ? 0 : sum[i - 1]);
        if (((cur & mask) | greedy) != greedy) {
          continue;
        }
        if (cur & (1LL << bit)) {
          tmp[1][j] = true;
        } else {
          tmp[0][j] = true;
        }
      }
      adj[i][0] = tmp[0];
      adj[i][1] = tmp[1];
    }
    memset(f, 0, sizeof(f));
    f[0][0][0] = true;
    for (int i = 0; i < n; i++) {
      tmp[0].reset();
      tmp[1].reset();
      for (int j = i; j < n; j++) {
        if (f[i][j][0]) {
          tmp[0] |= adj[j][0];
          tmp[1] |= adj[j][1];
        }
        if (f[i][j][1]) {
          tmp[1] |= adj[j][0];
          tmp[1] |= adj[j][1];
        }
      }
      for (int j = 0; j < n; j++) {
        f[i + 1][j + 1][0] = tmp[0][j];
        f[i + 1][j + 1][1] = tmp[1][j];
      }
    }
    bool ada = false;
    for (int i = p; i <= q; i++) {
      if (f[i][n][0]) {
        ada = true;
      }
    }
    if (!ada) {
      greedy |= 1LL << bit;
    }
    mask |= 1LL << bit;
  }
  cout << greedy << endl;
  return 0;
}
