#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)

int N, A, B;
int D[2001];
int maxD;

typedef long long ll;

const ll INF = 1LL << 57LL;

namespace subtask1
{
    ll ans;

    void go(int pos, int parts, ll sum, ll orr)
    {
        if (pos == N)
        {
            if (A <= parts && parts <= B)
                ans = min(ans, sum | orr);
            return;
        }

        // take
        go(pos + 1, parts, sum + D[pos], orr);

        // make new partition
        go(pos + 1, parts + 1, D[pos], orr | sum);
    }

    ll solve()
    {
        ans = INF;
        go(1, 1, D[0], 0);

        return ans;
    }

    bool satisfies()
    {
        return true
            && 1 <= N && N <= 20
            && 1 <= A && A <= B && B <= N
            && 0 <= maxD && maxD <= 1000000000
        ;
    }
}

namespace subtask2
{
    bool dp[51][1<<9][21];

    ll solve()
    {
        dp[0][0][0] = true;
        REP(i, N) REP(orr, 1<<9) REP(parts, B)
        {
            int sum = 0;
            FOR(j, i, N)
            {
                sum += D[j];
                dp[j + 1][orr | sum][parts + 1] |= dp[i][orr][parts];
            }
        }

        REP(orr, 1<<9) FOR(parts, A, B+1)
            if (dp[N][orr][parts])
                return orr;
    }

    bool satisfies()
    {
        return true
            && 1 <= N && N <= 50
            && 1 <= A && A <= B && B <= min(20, N)
            && 0 <= maxD && maxD <= 10
        ;
    }
}

namespace subtask3
{
    ll dp[101][1<<11];

    ll solve()
    {
        REP(i, N+1) REP(orr, 1<<11)
            dp[i][orr] = INF;

        dp[0][0] = 0;
        REP(i, N) REP(orr, 1<<11)
        {
            int sum = 0;
            FOR(j, i, N)
            {
                sum += D[j];
                dp[j + 1][orr | sum] = min(dp[j + 1][orr | sum], 1 + dp[i][orr]);
            }
        }

        REP(orr, 1<<11)
            if (dp[N][orr] <= B)
                return orr;
    }

    bool satisfies()
    {
        return true
            && 1 <= N && N <= 100
            && A == 1
            && 1 <= B <= N
            && 0 <= maxD && maxD <= 20
        ;
    }
}

namespace subtask4
{
    bool dp[101][101];
    ll ans;

    bool can()
    {
        memset(dp, false, sizeof dp);

        dp[0][0] = true;
        REP(i, N) REP(parts, B)
        {
            ll sum = 0;
            FOR(j, i, N)
            {
                sum += D[j];
                if ((sum | ans) == ans)
                    dp[j + 1][parts + 1] |= dp[i][parts];
            }
        }

        FOR(parts, A, B+1)
            if (dp[N][parts])
                return true;
        return false;
    }

    ll solve()
    {
        ans = (1LL<<57) - 1;
        for (ll bit = 56; bit >= 0; bit--)
        {
            ans ^= 1LL<<bit;

            if (!can())
                ans |= 1LL<<bit;
        }

        return ans;
    }

    bool satisfies()
    {
        return true
            && 1 <= N && N <= 100
            && 1 <= A && A <= B && B <= N
            && 0 <= maxD && maxD <= 1000000000
        ;
    }
}

namespace subtask5
{
    ll dp[2001];
    ll ans;

    bool can()
    {
        REP(i, N+1)
            dp[i] = INF;

        dp[0] = 0;
        REP(i, N)
        {
            ll sum = 0;
            FOR(j, i, N)
            {
                sum += D[j];
                if ((sum | ans) == ans)
                    dp[j + 1] = min(dp[j + 1], 1 + dp[i]);
            }
        }

        return dp[N] <= B;
    }

    ll solve()
    {
        ans = (1LL<<57) - 1;
        for (ll bit = 56; bit >= 0; bit--)
        {
            ans ^= 1LL<<bit;

            if (!can())
                ans |= 1LL<<bit;
        }

        return ans;
    }

    bool satisfies()
    {
        return true
            && 1 <= N && N <= 2000
            && A == 1
            && 1 <= B && B <= N
            && 0 <= maxD && maxD <= 1000000000
        ;
    }
}

function<bool()> validators[] = {
    subtask1::satisfies,
    subtask2::satisfies,
    subtask3::satisfies,
    subtask4::satisfies,
    subtask5::satisfies,
};

function<ll()> solvers[] = {
    subtask1::solve,
    subtask2::solve,
    subtask3::solve,
    subtask4::solve,
    subtask5::solve,
};

int main()
{
    cin >> N >> A >> B;
    REP(i, N)
        cin >> D[i];
    maxD = *max_element(D, D+N);

    vector<ll> answers;

    REP(i, 5)
        if (validators[i]())
        {
            //cerr << "Subtask " << (i+1) << ": " << solvers[i]() << endl;
            answers.push_back(solvers[i]());
        }

    sort(answers.begin(), answers.end());
    assert(answers.front() == answers.back());
    cout << answers.front() << endl;
}
