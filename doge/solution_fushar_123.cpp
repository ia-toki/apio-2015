#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)

typedef long long ll;

const ll INF = (ll)1e13;
const int MAXN = 2005, MAXP = 2005, MAXM = 2005;

int N, M;
int B[MAXM], P[MAXM];

priority_queue<tuple<ll, int>> pq;
ll dist[MAXM];

ll solve()
{
    REP(i, M)
        dist[i] = INF;

    dist[0] = 0;
    pq.emplace(0, 0);

    while (!pq.empty())
    {
        ll d;
        int doge;
        tie(d, doge) = pq.top();
        pq.pop();

        if (-d > dist[doge])
            continue;

        if (doge == 1)
            return -d;

        // move and pass news
        REP(new_doge, M) if (abs(B[doge] - B[new_doge]) % P[doge] == 0)
        {
            int w = abs(B[doge] - B[new_doge]) / P[doge];
            if (dist[new_doge] > dist[doge] + w)
            {
                dist[new_doge] = dist[doge] + w;
                pq.emplace(-dist[new_doge], new_doge);
            }
        }
    }

    return -1;
}


int main()
{
    cin >> N >> M;
    REP(i, M)
        cin >> B[i] >> P[i];

    cout << solve() << endl;
}
