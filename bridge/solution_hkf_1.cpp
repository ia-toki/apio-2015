#include <bits/stdc++.h>

using namespace std;

int B, N;
vector<pair<int, int> > P;

long long solve()
{
    vector<pair<int, int> > p = P;
    int n = p.size();
    if (n == 0) return 0;
    long long ans = 1e18;
    for (int i = 0; i < n; ++i)
    {
        long long tmp1 = 0, tmp2 = 0;
        for (int j = 0; j < n; ++j)
        {
            tmp1 += abs(p[i].first - p[j].first) + abs(p[i].first - p[j].second);
            tmp2 += abs(p[i].second - p[j].first) + abs(p[i].second - p[j].second);
        }
        ans = min(ans, min(tmp1, tmp2));
    }
    return ans + n;
}

int main()
{
    scanf("%d %d", &B, &N);
    long long ans = 0;
    for (int i = 0; i < N; ++i)
    {
        char a[10], b[10];
        int s, e;
        scanf("%s %d %s %d", a, &s, b, &e);
        if (a[0] == b[0])
            ans += abs(e - s);
        else
            P.push_back(make_pair(min(s, e), max(s, e)));
    }
    printf("%lld\n", ans + solve());
    return 0;
}
