#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)

typedef long long ll;

const ll INF = (ll)1e13;
const int MAXN = 10, MAXM = 3;

int N, M;
int B[MAXM], P[MAXM];

map<vector<int>, ll> dist;
priority_queue<tuple<ll, vector<int>>> pq;

ll solve()
{
    vector<int> init_state;
    REP(i, M)
        init_state.push_back(B[i]);
    init_state.push_back(0);

    dist[init_state] = 0;
    pq.emplace(0, init_state);

    while (!pq.empty())
    {
        ll d;
        vector<int> state;
        tie(d, state) = pq.top();
        pq.pop();

        if (-d > dist[state])
            continue;

        int doge = state.back();

        if (doge == 1)
            return -d;

        // move
        for (int sign = -1; sign <= 1; sign += 2)
        {
            vector<int> new_state = state;

            int new_building = new_state[doge] + sign * P[doge];
            if (new_building < 0 || new_building >= N)
                continue;

            new_state[doge] = new_building;
            if (!dist.count(new_state) || dist[new_state] > dist[state] + 1)
            {
                dist[new_state] = dist[state] + 1;
                pq.emplace(-dist[new_state], new_state);
            }
        }

        // pass news
        REP(new_doge, M) if (new_doge != doge && state[new_doge] == state[doge])
        {
            vector<int> new_state = state;
            new_state[M] = new_doge;

            if (!dist.count(new_state) || dist[new_state] > dist[state])
            {
                dist[new_state] = dist[state];
                pq.emplace(-dist[new_state], new_state);
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
