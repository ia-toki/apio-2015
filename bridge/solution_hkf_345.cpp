#include <bits/stdc++.h>

using namespace std;

int B, N;
vector<pair<int, int> > P;

vector<pair<int, int> > p;
int n;

long long solveSubtask2()
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

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return (a.first + a.second) < (b.first + b.second);
}

vector<long long> compute()
{
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int> > min_heap;
    long long sumMax = p[0].first, sumMin = p[0].second;

    max_heap.push(p[0].first);
    min_heap.push(p[0].second);

    vector<long long> tmp;
    tmp.push_back(sumMin - sumMax);

    for (int i = 1; i < n; ++i)
    {
        int m = max_heap.top();
        int M = min_heap.top();
        int A = p[i].first, B = p[i].second;
        if (A <= m && B <= m)
        {
            max_heap.pop();
            max_heap.push(A);
            max_heap.push(B);
            min_heap.push(m);
            sumMax += A + B - m;
            sumMin += m;
        }
        else
        if (A >= M && B >= M)
        {
            min_heap.pop();
            min_heap.push(A);
            min_heap.push(B);
            max_heap.push(M);
            sumMin += A + B - M;
            sumMax += M;
        }
        else
        {
            max_heap.push(A);
            min_heap.push(B);
            sumMax += A;
            sumMin += B;
        }
        tmp.push_back(sumMin - sumMax);
    }
    return tmp;
}

long long solve()
{
    p = P;
    sort(p.begin(), p.end(), cmp);
    n = p.size();
    if (n == 0) return 0;

    vector<long long> val1n = compute();
    reverse(p.begin(), p.end());
    vector<long long> valn1 = compute();

    long long ans = 1e18;
    for (int i = 0; i < n - 1; ++i)
        ans = min(ans, val1n[i] + valn1[n - i - 2]);
    return min(ans + n, solveSubtask2());
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
