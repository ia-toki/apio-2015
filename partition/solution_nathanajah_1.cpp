#include <bits/stdc++.h>
using namespace std;

int n, a, b;
int d[25];
long long result = 1000000000000000000LL;

void backtrack(int index, long long cur_sum, long long cur_res, int num_partition) {
  if (index == n) {
    if (num_partition >= a && num_partition <= b) {
      result = min(result, cur_sum | cur_res);
    }
    return;
  }
  //start new partition
  backtrack(index + 1, d[index], cur_res | cur_sum, num_partition + 1);
  backtrack(index + 1, d[index] + cur_sum, cur_res, num_partition);

}

int main() {
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 0; i < n; i++) {
    scanf("%d", &d[i]);
  }
  backtrack(1, d[0], 0, 1);
  printf("%lld\n", result);
}
