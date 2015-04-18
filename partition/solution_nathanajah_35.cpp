#include <bits/stdc++.h>
using namespace std;

int n;
long long d[105];
int a, b;

bool can(long long mask) {
  int dp[1005];

  for (int i = 0; i <= n; i++) {
    dp[i] = 100000;
  }
  dp[0] = 0;

  for (int i = 0; i < n; i++) {
    if (dp[i] < 100000) {
      long long cur_sum = 0;
      for (int j = i; j < n; j++) {
        cur_sum += d[j];
        if ((cur_sum & mask) == 0) {
          dp[j+1] = min(dp[j+1], dp[i] + 1);
        }
      }
    }
  }
  return dp[n] <= b;
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
