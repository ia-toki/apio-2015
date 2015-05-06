#include "tcframe/runner.hpp"
using namespace tcframe;

#include <algorithm>
#include <random>
#include <bitset>
using namespace std;

class Problem : public BaseProblem
{
protected:
	int N;
	vector<int> P;
	vector<int> B;
	int M;

	int result;

	void Config()
	{
		setSlug("doge");
	}

	void InputFormat()
	{
		LINE(N, M);
		LINES(B, P) % SIZE(M);
	}

	void OutputFormat()
	{
		LINE(result);
	}

	void Subtask1()
	{
		CONS(1 <= N && N <= 10);
		CONS(eachElementBetween(B, 0, N - 1));
		CONS(eachElementBetween(P, 1, 10));
		CONS(2 <= M && M <= 3);
	}

	void Subtask2()
	{
		CONS(1 <= N && N <= 100);
		CONS(eachElementBetween(B, 0, N - 1));
		CONS(eachElementBetween(P, 1, 100));
		CONS(2 <= M && M <= 2000);
	}

	void Subtask3()
	{
		CONS(1 <= N && N <= 2000);
		CONS(eachElementBetween(B, 0, N - 1));
		CONS(eachElementBetween(P, 1, 2000));
		CONS(2 <= M && M <= 2000);
	}

	void Subtask4()
	{
		CONS(1 <= N && N <= 2000);
		CONS(eachElementBetween(B, 0, N - 1));
		CONS(eachElementBetween(P, 1, 2000));
		CONS(2 <= M && M <= 50000);
	}

	void Subtask5()
	{
		CONS(1 <= N && N <= 50000);
		CONS(eachElementBetween(B, 0, N - 1));
		CONS(eachElementBetween(P, 1, 50000));
		CONS(2 <= M && M <= 50000);
	}

private:
	bool eachElementBetween(const vector<int> &A, int lo, int hi)
	{
		for (int x : A)
			if (x < lo || x > hi)
				return false;
		return true;
	}
};

class Generator : public BaseGenerator<Problem>
{
public:
	Generator()
	{
		mt_rand = mt19937(283432091);
	}

protected:
	void SampleTestCases()
	{
		SAMPLE_CASE
		({
			"5 3",
			"0 2",
			"1 1",
			"4 1"
		}, {1, 2, 3, 4, 5});
	}

	void TestGroup1()
	{
		// CONS(1 <= N && N <= 10);
		// CONS(eachElementBetween(B, 0, N - 1));
		// CONS(eachElementBetween(P, 1, 10));
		// CONS(2 <= M && M <= 3);

		assignToSubtasks({1, 2, 3, 4, 5});

		CASE(N = 1, M = 2, randomArray(1, 1));
		CASE(N = 6, M = 3, randomArray(2, 4));
		CASE(N = 7, M = 3, randomArray(1, 10));
		CASE(N = 10, M = 3, randomArray(1, 10));
		CASE(N = 10, M = 3, prime());
		CASE(N = 10, M = 3, one());
	}

	void TestGroup2()
	{
		// CONS(1 <= N && N <= 100);
		// CONS(eachElementBetween(B, 0, N - 1));
		// CONS(eachElementBetween(P, 1, 100));
		// CONS(2 <= M && M <= 2000);

		assignToSubtasks({2, 3, 4, 5});

		CASE(N = 37, M = 19, randomArray(1, 100));
		CASE(N = 59, M = 48, randomArray(1, 58));
		CASE(N = 100, M = randomInt(2, 1000), randomArray(1, 100));
		CASE(N = 100, M = 2000, randomArray(1, 100));
		CASE(N = 100, M = 2000, prime());
		CASE(N = 100, M = 2000, one());
	}

	void TestGroup3()
	{
		// CONS(1 <= N && N <= 2000);
		// CONS(eachElementBetween(B, 0, N - 1));
		// CONS(eachElementBetween(P, 1, 2000));
		// CONS(2 <= M && M <= 2000);

		assignToSubtasks({3, 4, 5});

		CASE(N = 200, M = randomInt(2, 2000), randomArray(1, 199));
		CASE(N = 742, M = randomInt(500, 2000), randomArray(1, 441));
		CASE(N = 1747, M = randomInt(500, 2000), randomArray(1, 2000));
		CASE(N = 2000, M = randomInt(500, 2000), randomArray(1, 2000));
		CASE(N = 2000, M = 2000, one());

		CASE(N = randomInt(101, 2000), M = randomInt(2, 2000), randomArray(1, 2000));
		CASE(N = randomInt(201, 2000), M = randomInt(20, 2000), randomArray(1, 2000));
		CASE(N = randomInt(1001, 2000), M = randomInt(700, 1000), randomArray(1, 2000));
		CASE(N = randomInt(1801, 2000), M = randomInt(1500, 2000), randomArray(1, 2000));
		CASE(N = 2000, M = 2000, array(500, 2000));

		CASE(N = 2000, M = 2000, backback(100, 2));
		CASE(N = 2000, M = 2000, prime());
	}

	void TestGroup4()
	{
		// CONS(1 <= N && N <= 2000);
		// CONS(eachElementBetween(B, 0, N - 1));
		// CONS(eachElementBetween(P, 1, 2000));
		// CONS(2 <= M && M <= 50000);

		assignToSubtasks({4, 5});

		CASE(N = randomInt(1001, 2000), M = randomInt(2001, 50000), randomArray(1, 2000));
		CASE(N = randomInt(1001, 2000), M = randomInt(2001, 50000), randomArray(1, 2000));
		CASE(N = 1938, M = 29374, randomArray(1, 937));
		CASE(N = 1997, M = 49997, randomArray(1, 2000));
		CASE(N = 2000, M = 50000, randomArray(1, 2000));

		CASE(N = 2000, M = 50000, array(1, 2000));
		CASE(N = 1999, M = 50000, array(1, 2000));
		CASE(N = 2000, M = 50000, backback(100, 2));
		CASE(N = 2000, M = 50000, prime());
		CASE(N = 2000, M = 50000, one());
	}

	void TestGroup5()
	{
		// CONS(1 <= N && N <= 50000);
		// CONS(eachElementBetween(B, 0, N - 1));
		// CONS(eachElementBetween(P, 1, 50000));
		// CONS(2 <= M && M <= 50000);

		assignToSubtasks({5});

		CASE(N = 12345, M = 34321, randomArray(1, 2384));
		CASE(N = 43221, M = 42370, randomArray(1, 23482));
		CASE(N = randomInt(40000, 50000), M = randomInt(40000, 50000), randomArray(1, 50000));
		CASE(N = randomInt(10001, 50000), M = randomInt(2, 50000), randomArray(1, 50000));
		CASE(N = 50000, M = 50000, randomArray(1, 50000));

		CASE(N = 50000, M = 50000, array(1, 50000));
		CASE(N = 50000, M = 50000, array(25001, 50000));
		CASE(N = 49999, M = 2, jump(110, 17));
		CASE(N = 49999, M = 4, array(1, 50000));
		CASE(N = 50000, M = 4, array(1, 50000));

		CASE(N = 50000, M = 50000, one());
		CASE(N = 50000, M = 2471, smallprime(13));
		CASE(N = 50000, M = 50000, backback(10, 6));
		CASE(N = 50000, M = 50000, backback(30, 2));
		CASE(N = 50000, M = 50000, backback(200, 2));

		CASE(N = 50000, M = 50000, prime());
		CASE(N = 49999, M = 50000, prime());
	}

private:
	mt19937 mt_rand;

	int randomInt(int l, int r)
	{
		uniform_int_distribution<int> dist(l, r);
		return dist(mt_rand);
	}

	void randomArray(int l = 1, int r = 50000)
	{
		uniform_int_distribution<int> dist(l, r);
		B.clear();
		P.clear();
		for (int i = 0; i < M; ++i)
		{
			B.push_back(randomInt(0, N - 1));
			P.push_back(dist(mt_rand));
		}
	}

	void array(int l, int r)
	{
		B.clear();
		P.clear();
		B.push_back(N - 2); P.push_back(2);
		B.push_back(1); P.push_back(1);
		B.push_back(0); P.push_back(3);
		B.push_back(N - 1); P.push_back(1);
		for (int i = 4; i < M; ++i)
		{
			B.push_back(randomInt(0, N - 1));
			P.push_back(randomInt(l, r));
		}
	}

	void jump(int p0, int p1, int l = 1, int r = 50000)
	{
		B.clear();
		P.clear();
		B.push_back(p0); P.push_back(2);
		B.push_back(p1); P.push_back(2);
		for (int i = 2; i < M; ++i)
		{
			B.push_back(randomInt(0, N - 1));
			P.push_back(randomInt(l, r));
		}
	}

	void smallprime(int lnum)
	{
		int pr[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 47, 59, 67, 91};
		B.clear();
		P.clear();
		B.push_back(1); P.push_back(2);
		B.push_back(0); P.push_back(N - 3);
		int last = 1, step = 2;
		for (int i = 2; i < M; ++i)
		{
			int pos = randomInt(1, N / step);
			B.push_back(pos * step);
			P.push_back(pr[randomInt(0, lnum)]);
			last = B.back();
			step = P.back();
		}
	}

	void one()
	{
		B.clear();
		P.clear();
		B.push_back(0); P.push_back(1);
		B.push_back(N - 1); P.push_back(1);
		for (int i = 2, p = 1; i < M; ++i)
		{
			B.push_back(min(p, N - 2));
			++p;
			P.push_back(1);
		}
		random_shuffle(B.begin() + 2, B.end());
	}

	void backback(int lim, int plus)
	{
		int tmp = M - 2;
		bitset<50000> vis;
		B.clear();
		P.clear();
		B.push_back(0); P.push_back(2);
		int last = 0;
		for (int i = 0; i < N; i += 2)
		{
			last = i;
			vis[i] = 1;
		}
		B.push_back(N - 1); P.push_back(1);
		for (int k = 0, step = 3; tmp - 2 >= 0 && k < lim; ++k, tmp -= 2)
		{
			B.push_back(last); P.push_back(step);
			for (int i = last; i >= 0; i -= step)
			{
				if (!vis[i])
					last = i;
				vis[i] = 1;
			}
			step += plus;
			B.push_back(last); P.push_back(step);
			for (int i = last; i < N; i += step)
			{
				if (!vis[i])
					last = i;
				vis[i] = 1;
			}
		}
		while (tmp--)
		{
			B.push_back(last);
			P.push_back(1);
		}
	}

	void prime()
	{
		B.clear();
		P.clear();
		vector<int> lp, pos;
		bitset<50000> bs;
		B.push_back(0); P.push_back(2);
		for (int i = 3; i < N; i += 2)
			if (!bs[i])
			{
				lp.push_back(i);
				for (long long j = (long long) i * i; j < N; j += i + i)
					bs[j] = 1;
			}
		bitset<50000> vis;
		int last = 0;
		for (int i = 0; i < N; i += 2)
		{
			last = i;
			vis[i] = 1;
		}
		int tmp = M - 2;
		for (int j = 0, sign = -1; j < (int) lp.size() && tmp > 0; ++j, --tmp, sign = -sign)
		{
			pos.push_back(last);
			if (sign < 0)
			{
				for (int i = last; i > 0; i -= lp[j])
					if (!vis[i])
					{
						last = i;
						vis[i] = 1;
					}
			}
			else
			{
				for (int i = last; i < N; i += lp[j])
					if (!vis[i])
					{
						last = i;
						vis[i] = 1;
					}
			}
		}
		B.push_back(last); P.push_back(1);
		for (int j = 0; j < (int) pos.size(); ++j)
		{
			B.push_back(pos[j]);
			P.push_back(lp[j]);
		}
		while(tmp--)
		{
			B.push_back(last);
			P.push_back(1);
		}
	}
};

int main(int argc, char* argv[])
{
	Runner<Problem> runner(argc, argv);
	runner.setGenerator(new Generator());

	return runner.run();
}
