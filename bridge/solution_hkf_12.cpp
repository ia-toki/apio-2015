#include <bits/stdc++.h>

using namespace std;

int B, N;
vector<pair<int, int> > P;

long long solve()
{
    long long ans = 0;
    vector<int> x;
    int n = P.size();
    if (n == 0) return 0;
    for (int i = 0; i < n; ++i)
    {
        x.push_back(P[i].first);
        x.push_back(P[i].second);
        ans -= P[i].first + P[i].second;
    }
    sort(x.begin(), x.end());
    for (int i = 2 * n - 1; i >= n; --i)
        ans += 2 * x[i];
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
