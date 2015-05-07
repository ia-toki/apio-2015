#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)

typedef long long ll;

const ll INF = (ll)1e13;
const int MAXN = 2005, MAXP = 2005, MAXM = 30005;

int N, M;
int B[MAXM], P[MAXM];

priority_queue<tuple<ll, int, int>> pq;
ll dist[MAXN][MAXP];
vector<int> powers[2001];

ll solve()
{
    REP(i, M)
        powers[B[i]].push_back(P[i]);

    REP(i, N) REP(j, MAXP)
        dist[i][j] = INF;

    dist[B[0]][P[0]] = 0;
    pq.emplace(0, B[0], P[0]);

    while (!pq.empty())
    {
        ll d;
        int building, power;
        tie(d, building, power) = pq.top();
        pq.pop();

        if (-d > dist[building][power])
            continue;

        if (building == B[1])
            return -d;

        // in a building
        if (power == 0)
        {
            for (int new_power : powers[building])
                if (dist[building][new_power] > dist[building][power])
                {
                    dist[building][new_power] = dist[building][power];
                    pq.emplace(-dist[building][new_power], building, new_power);
                }
        }
        else
        {
            // pass news
            if (dist[building][0] > dist[building][power])
            {
                dist[building][0] = dist[building][power];
                pq.emplace(-dist[building][0], building, 0);
            }

            // move
            for (int sign = -1; sign <= 1; sign += 2)
            {
                int new_building = building + sign * power;
                if (new_building < 0 || new_building >= N)
                    continue;
                if (dist[new_building][power] > dist[building][power] + 1)
                {
                    dist[new_building][power] = dist[building][power] + 1;
                    pq.emplace(-dist[new_building][power], new_building, power);
                }
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
