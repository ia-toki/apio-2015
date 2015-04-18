#include <stdio.h>

int main()
{
	int n, m, a, b, ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &a, &b);
		ans += a & b;
	}
	printf("%d\n", ans);
	return 0;
}