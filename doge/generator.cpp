#include "tcframe/tcframe.hpp"
using namespace tcframe;

#include <random>
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
		CONS(eachElementBetween(P, 1, 9));
		CONS(2 <= M && M <= 3);
	}
	
	void Subtask2()
	{
		CONS(1 <= N && N <= 100);
		CONS(eachElementBetween(B, 0, N - 1));
		CONS(eachElementBetween(P, 1, 99));
		CONS(2 <= M && M <= 1000);
	}
	
	void Subtask3()
	{
		CONS(1 <= N && N <= 1000);
		CONS(eachElementBetween(B, 0, N - 1));
		CONS(eachElementBetween(P, 1, 999));
		CONS(2 <= M && M <= 1000);
	}
	
	void Subtask4()
	{
		CONS(1 <= N && N <= 1000);
		CONS(eachElementBetween(B, 0, N - 1));
		CONS(eachElementBetween(P, 1, 999));
		CONS(2 <= M && M <= 10000);
	}
	
	void Subtask5()
	{
		CONS(1 <= N && N <= 10000);
		CONS(eachElementBetween(B, 0, N - 1));
		CONS(eachElementBetween(P, 1, 9999));
		CONS(2 <= M && M <= 10000);
	}

	void Subtask6()
	{
		CONS(1 <= N && N <= 50000);
		CONS(eachElementBetween(B, 0, N - 1));
		CONS(eachElementBetween(P, 1, 49999));
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
	void Config()
	{
		setBaseDir("tc");
		setSolution("./solution");
	}

	void SampleTestCases()
	{
		SAMPLE_CASE
		({
			"5 3",
			"0 2",
			"1 1",
			"4 1"
		}, {1, 2, 3, 4, 5, 6});
	}

	void TestGroup1()
	{
		// CONS(1 <= N <= 10);
		// CONS(eachElementBetween(B, 0, N - 1));
		// CONS(eachElementBetween(P, 1, 9));
  		// CONS(2 <= M <= 3);

		assignToSubtasks({1, 2, 3, 4, 5, 6});

		CASE(N = 1, M = 2, randomArray(1, 1));
		CASE(N = 6, M = 3, randomArray(2, 4));
		CASE(N = 7, M = 3, randomArray(1, 9));
		CASE(N = 10, M = 3, randomArray(1, 9));
	}

	void TestGroup2()
	{
		// CONS(1 <= N <= 100);
		// CONS(eachElementBetween(B, 0, N - 1));
		// CONS(eachElementBetween(P, 1, 99));
		// CONS(2 <= M <= 1000);

		assignToSubtasks({2, 3, 4, 5, 6});

		CASE(N = 15, M = 4, randomArray(1, 14));
		CASE(N = 21, M = 7, randomArray(1, 20));
		CASE(N = 37, M = 19, randomArray(1, 99));
		CASE(N = 59, M = 48, randomArray(1, 58));
		CASE(N = 81, M = randomInt(2, 1000), randomArray(1, 99));
		CASE(N = 100, M = randomInt(2, 1000), randomArray(1, 99));
		CASE(N = 100, M = 1000, randomArray(1, 99));
	}

	void TestGroup3()
	{
		// CONS(1 <= N <= 1000);
		// CONS(eachElementBetween(B, 0, N - 1));
		// CONS(eachElementBetween(P, 1, 999));
		// CONS(2 <= M <= 1000);

		assignToSubtasks({3, 4, 5, 6});

		CASE(N = 200, M = randomInt(2, 1000), randomArray(1, 199));
		CASE(N = 442, M = randomInt(500, 1000), randomArray(1, 441));
		CASE(N = 747, M = randomInt(500, 1000), randomArray(1, 999));
		CASE(N = 1000, M = randomInt(500, 1000), randomArray(1, 999));
		CASE(N = randomInt(101, 1000), M = randomInt(2, 1000), randomArray(1, 999));
		CASE(N = randomInt(201, 1000), M = randomInt(20, 1000), randomArray(1, 999));
		CASE(N = randomInt(401, 1000), M = randomInt(200, 1000), randomArray(1, 999));
		CASE(N = randomInt(801, 1000), M = randomInt(700, 1000), randomArray(1, 999));
		CASE(N = 1000, M = 1000, array(200, 999));
	}

	void TestGroup4()
	{
		// CONS(1 <= N <= 1000);
		// CONS(eachElementBetween(B, 0, N - 1));
		// CONS(eachElementBetween(P, 1, 999));
		// CONS(2 <= M <= 10000);

		assignToSubtasks({4, 5, 6});

		CASE(N = randomInt(101, 1000), M = randomInt(1001, 10000), randomArray(1, 999));
		CASE(N = randomInt(101, 1000), M = randomInt(1001, 10000), randomArray(1, 999));
		CASE(N = 527, M = 1237, randomArray(1, 999));
		CASE(N = 938, M = 9374, randomArray(1, 637));
		CASE(N = 997, M = 9997, randomArray(1, 999));
		CASE(N = 1000, M = 10000, randomArray(1, 999));
		CASE(N = 1000, M = 10000, array(1, 999));
	}

	void TestGroup5()
	{
		// CONS(1 <= N <= 10000);
		// CONS(eachElementBetween(B, 0, N - 1));
		// CONS(eachElementBetween(P, 1, 9999));
		// CONS(2 <= M <= 10000);

		assignToSubtasks({5, 6});

		CASE(N = 2341, M = 7334, randomArray(1, 2171));
		CASE(N = 3274, M = 2375, randomArray(10, 2731));
		CASE(N = 5722, M = 9239, randomArray(234, 3374));
		CASE(N = 7423, M = 9831, randomArray(1, 9999));
		CASE(N = randomInt(1001, 10000), M = randomInt(2, 10000), randomArray(1, 9999));
		CASE(N = randomInt(1001, 10000), M = randomInt(2, 10000), randomArray(1, 9999));
		CASE(N = 10000, M = 10000, randomArray(1, 9999));
		CASE(N = 10000, M = 5000, array(1, 9999));
		CASE(N = 10000, M = 10000, array(1, 9999));
		CASE(N = 9999, M = 2, jump(4, 7));
	}

	void TestGroup6()
	{
		// CONS(1 <= N <= 50000);
		// CONS(eachElementBetween(B, 0, N - 1));
		// CONS(eachElementBetween(P, 1, 49999));
		// CONS(2 <= M <= 50000);

		assignToSubtasks({6});

		CASE(N = 12345, M = 34321, randomArray(1, 2384));
		CASE(N = 23456, M = 49234, randomArray(1, 23144));
		CASE(N = 43221, M = 42370, randomArray(1, 23482));
		CASE(N = 49814, M = 23948, randomArray(1, 24907));
		CASE(N = randomInt(40000, 50000), M = randomInt(40000, 50000), randomArray(23481, 23497));
		CASE(N = randomInt(40000, 50000), M = randomInt(40000, 50000), randomArray(1, 49999));
		CASE(N = randomInt(10001, 50000), M = randomInt(10001, 50000), randomArray(1, 49999));
		CASE(N = randomInt(10001, 50000), M = randomInt(2, 50000), randomArray(1, 49999));
		CASE(N = 50000, M = 50000, randomArray(1, 49999));
		CASE(N = 50000, M = 50000, array(1, 49999));
		CASE(N = 50000, M = 50000, array(25001, 49999));
		CASE(N = 49999, M = 2, jump(110, 17));
		CASE(N = 49999, M = 4, array(1, 49999));
		CASE(N = 50000, M = 4, array(1, 49999));
		CASE(N = 50000, M = 2471, prime(13));
		CASE(N = 50000, M = 24711, prime(11));
		CASE(N = 50000, M = 2, prime(10));
	}

private:
	mt19937 mt_rand;

	int randomInt(int l, int r)
	{
		uniform_int_distribution<int> dist(l, r);
		return dist(mt_rand);
	}

	void randomArray(int l = 1, int r = 49999)
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
		B.push_back(N - 2);
		B.push_back(1);
		B.push_back(0);
		B.push_back(N - 1);
		P.push_back(2);
		P.push_back(1);
		P.push_back(3);
		P.push_back(1);
		for (int i = 4; i < M; ++i)
		{
			B.push_back(randomInt(0, N - 1));
			P.push_back(randomInt(l, r));
		}
	}

	void jump(int p0, int p1, int l = 1, int r = 49999)
	{
		B.clear();
		P.clear();
		B.push_back(p0);
		B.push_back(p1);
		P.push_back(2);
		P.push_back(2);
		for (int i = 2; i < M; ++i)
		{
			B.push_back(randomInt(0, N - 1));
			P.push_back(randomInt(l, r));
		}
	}

	void prime(int lnum)
	{
		int pr[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 47, 59, 67, 91};
		B.clear();
		P.clear();
		B.push_back(1);
		P.push_back(2);
		B.push_back(0);
		P.push_back(N - 3);
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
};

int main()
{
    Generator gen;
    return gen.generate();
}