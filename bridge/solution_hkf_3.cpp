#include <bits/stdc++.h>

using namespace std;

int B, N;
vector<pair<int, int> > P;

long long solve()
{
    long long ans = 1e18;
    int n = P.size();

    if (n == 0) return 0;

    vector<int> p;

    for (int i = 0; i < n; ++i)
    {
        p.push_back(P[i].first);
        p.push_back(P[i].second);
    }

    for (int i = 0; i < 2 * n; ++i)
        for (int j = 0; j < 2 * n; ++j)
        {
            long long tmp = 0;
            for (int k = 0; k < n; ++k)
            {
                int v1 = abs(P[k].first - p[i]) + abs(P[k].second - p[i]);
                int v2 = abs(P[k].first - p[j]) + abs(P[k].second - p[j]);
                tmp += min(v1, v2);
            }
            ans = min(ans, tmp);
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
