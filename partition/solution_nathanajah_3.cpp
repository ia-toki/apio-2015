#include <bits/stdc++.h>
using namespace std;

int dp[105][2005];
int n, a, b;
int d[105];
int INF = 1000000000;

int main() {
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 0; i < n; i++) {
    scanf("%d", &d[i]);
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= 2000; j++) {
      dp[i][j] = INF;
    }
  }

  dp[0][0] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 2000; j++) {
      if (dp[i][j] < INF) {
        int cur_sum = 0;
        for (int k = i; k < n; k++) {
          cur_sum += d[k];
          dp[k + 1][j | cur_sum] = min(dp[k + 1][j | cur_sum], dp[i][j] + 1);
        }
      }
    }
  }
  for (int i = 0; i <= 2000; i++) {
    if (dp[n][i] <= b) {
      printf("%d\n", i);
      return 0;
    }
  }
}
