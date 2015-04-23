#include <bits/stdc++.h>

using namespace std;

int B, N;
vector<pair<int, int> > P;

namespace subtask1
{
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

	bool satisfies()
	{
		return B == 1 && 1 <= N && N <= 1000;
	}
}

namespace subtask2
{
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

	bool satisfies()
	{
		return B == 1 && 1 <= N && N <= 100000;
	}
}

namespace subtask3
{
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

	bool satisfies()
	{
		return B == 2 && 1 <= N && N <= 100;
	}
}

namespace subtask4
{
	bool cmp(pair<int, int> a, pair<int, int> b)
	{
		return (a.first + a.second) < (b.first + b.second);
	}

	long long compute(vector<pair<int, int> > P)
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

	long long solve()
	{
		long long ans = subtask2::solve();
		int n = P.size();
		if (n == 0) return 0;

		vector<pair<int, int> > p = P;
		sort(p.begin(), p.end(), cmp);

		for (int i = 1; i <= n; ++i)
		{
			ans = min(ans,
				compute(vector<pair<int, int> >(p.begin(), p.begin() + i)) +
				compute(vector<pair<int, int> >(p.begin() + i, p.end())));
		}
		return ans;
	}

	bool satisfies()
	{
		return B == 2 && 1 <= N && N <= 1000;
	}
}

namespace subtask5
{
	vector<pair<int, int> > p;
	int n;

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
		return min(ans + n, subtask2::solve());
	}

	bool satisfies()
	{
		return B == 2 && 1 <= N && N <= 100000;
	}
}

function<bool()> validators[] =
{
	subtask1::satisfies,
	subtask2::satisfies,
	subtask3::satisfies,
	subtask4::satisfies,
	subtask5::satisfies,
};

function<long long()> solvers[] =
{
	subtask1::solve,
	subtask2::solve,
	subtask3::solve,
	subtask4::solve,
	subtask5::solve
};

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
	vector<long long> answers;
	for (int i = 0; i < 5; ++i)
		if (validators[i]())
			answers.push_back(solvers[i]() + ans);

	sort(answers.begin(), answers.end());
	assert(answers.front() == answers.back());
	printf("%lld\n", answers[0]);
	return 0;
}