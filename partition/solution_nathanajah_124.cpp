#include <bits/stdc++.h>
using namespace std;

int n;
long long d[105];
int a, b;

bool can(long long mask) {
  bool dp[105][105];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = true;
  for (int j = 0; j <= b; j++) {
    for (int i = 0; i < n; i++) {
      if (dp[i][j]) {
        long long cur_sum = 0;
        for (int k = i; k < n; k++) {
          cur_sum += d[k];
          if ((cur_sum & mask) == 0) {
            dp[k+1][j+1] = true;
          }
        }
      }
    }
  }
  for (int i = a; i <= b; i++) {
    if (dp[n][i]) {
      return true;
    }
  }
  return false;
}

int main() {
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &d[i]);
  }
  long long cur_mask = 0;
  for (int i = 60; i >= 0; --i) {
    if (can(cur_mask | (1LL<<i))) {
      cur_mask = cur_mask | (1LL<<i);
    }
  }
  printf("%lld\n", (1LL<<61) -1 - cur_mask);
}
