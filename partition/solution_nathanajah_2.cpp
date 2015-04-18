#include <bits/stdc++.h>
using namespace std;

bool can[55][505][25];

int n, a, b;
int d[55];
int INF = 1000000000;

int main(){
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 0; i < n; i++) {
    scanf("%d", &d[i]);
  }

  can[0][0][0] = true;
  for (int k = 0; k <= b; k++) {
    for (int i = 0; i < n; i++) {
      for (int j =0; j <= 500; j++) {
        if (can[i][j][k]) {
          int cur_sum =0;
          for (int last_index = i; last_index < n; last_index++) {
            cur_sum += d[last_index];
            can[last_index + 1][j | cur_sum][k + 1] = true;
          }
        }
      }
    }
  }
  int res = 1000;
  for (int j = a; j <= b; j++) {
    for (int i = 0; i <= 500; i++) {
      if (can[n][i][j]) {
        res = min(res, i);
      }
    }
  }
  printf("%d\n", res);
}
