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
		CONS(2 <= M && M <= 30000);
	}

	void Subtask5()
	{
		CONS(1 <= N && N <= 30000);
		CONS(eachElementBetween(B, 0, N - 1));
		CONS(eachElementBetween(P, 1, 30000));
		CONS(2 <= M && M <= 30000);
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
        CASE(lotsOfEdges(100, 2000, false));
        CASE(lotsOfEdges(100, 2000, true));
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

        CASE(Worst(2000));
        CASE(sqrtN(2000, 10, 40));
        CASE(sqrtN(2000, 20, 27));
        CASE(sqrtN(2000, 30, 45));
        CASE(sqrtN(2000, 40, 50));
        CASE(lotsOfEdges(2000, 2000, false));
        CASE(lotsOfEdges(2000, 2000, true));
	}

	void TestGroup4()
	{
		// CONS(1 <= N && N <= 2000);
		// CONS(eachElementBetween(B, 0, N - 1));
		// CONS(eachElementBetween(P, 1, 2000));
		// CONS(2 <= M && M <= 30000);

		assignToSubtasks({4, 5});

		CASE(N = randomInt(1001, 2000), M = randomInt(2001, 30000), randomArray(1, 2000));
		CASE(N = randomInt(1001, 2000), M = randomInt(2001, 30000), randomArray(1, 2000));
		CASE(N = 1938, M = 19374, randomArray(1, 937));
		CASE(N = 1997, M = 29997, randomArray(1, 2000));
		CASE(N = 2000, M = 30000, randomArray(1, 2000));

		CASE(N = 2000, M = 30000, array(1, 2000));
		CASE(N = 1999, M = 30000, array(1, 2000));
		CASE(N = 2000, M = 30000, backback(100, 2));
		CASE(N = 2000, M = 30000, prime());
		CASE(N = 2000, M = 30000, one());
        CASE(lotsOfEdges(2000, 30000, false));
        CASE(lotsOfEdges(2000, 30000, true));
	}

	void TestGroup5()
	{
		// CONS(1 <= N && N <= 30000);
		// CONS(eachElementBetween(B, 0, N - 1));
		// CONS(eachElementBetween(P, 1, 30000));
		// CONS(2 <= M && M <= 30000);

		assignToSubtasks({5});

		CASE(N = 12345, M = 24321, randomArray(1, 2384));
		CASE(N = 23221, M = 22370, randomArray(1, 23482));
		CASE(N = randomInt(20000, 30000), M = randomInt(20000, 30000), randomArray(1, 30000));
		CASE(N = randomInt(10001, 30000), M = randomInt(2, 30000), randomArray(1, 30000));
		CASE(N = 30000, M = 30000, randomArray(1, 30000));

		CASE(N = 30000, M = 30000, array(1, 30000));
		CASE(N = 30000, M = 30000, array(25001, 30000));
		CASE(N = 29999, M = 2, jump(110, 17));
		CASE(N = 30000, M = 4, array(1, 30000));

		CASE(N = 30000, M = 30000, one());
		CASE(N = 30000, M = 2471, smallprime(13));
		CASE(N = 30000, M = 30000, backback(10, 6));
		CASE(N = 30000, M = 30000, backback(30, 2));
		CASE(N = 30000, M = 30000, backback(200, 2));

		CASE(N = 30000, M = 30000, prime());
        CASE(Worst(30000));
        CASE(WorstQuadratic(30000));
        CASE(sqrtN(30000, 200, 600));
        CASE(sqrtN(30000, 200, 450));
        CASE(sqrtN(30000, 100, 350));
        CASE(lotsOfEdges(30000, 30000, false));
        CASE(lotsOfEdges(30000, 30000, true));
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

    void Worst_AddLoc(set<pair<int, int>>& bads, int pos, int kMaxPow) {
        for (int j = 2; j < kMaxPow; j++)
            bads.insert(make_pair(j, pos%j));
    }

    void WorstQuadratic(int kMaxN) {
        B.clear();
        P.clear();
        for (int i = 0; i < kMaxN; i++) {
            B.push_back(i);
            P.push_back(1);
        }

        B[1] = N-1;
        B[2] = N-3;
        P[2] = 2;
    }

    void Worst(int kMaxN) {
        B.clear();
        P.clear();
        vector <pair<int,int> > dogeposes;
        int posdog = 0;
        vector <bool> touched;
        for (int i = 0; i < kMaxN; i++) {
          touched.push_back(false);
        }
        dogeposes.push_back(make_pair(posdog, 1));
        vector<int> doglocs;
        doglocs.push_back(posdog);
        touched[posdog] = 1;
        int bak = 1;
        int kMaxPow = 1000;
        set<pair<int, int>> bads;

        while (dogeposes.size() < kMaxN / 2) {
            bool found = false;
            for (int j = 2; j < kMaxN; j++) {
                if (j < kMaxPow) {
                    if (bads.count(make_pair(j, posdog%j)))
                        continue;
                } else {
                    bool failed = false;
                    for (int k = posdog % j; k < kMaxN; k += j) {
                        if (touched[k] && k != posdog)
                            failed = true;
                    }
                    if (failed)
                        continue;
                }

                found = false;
                vector<int> trang;

                if (bak == 1) {
                    for (int k = kMaxN-1; k >=0; k--)
                        trang.push_back(k);
                } else {
                    for (int k = 0; k < kMaxN; k++)
                        trang.push_back(k);
                }

                int targ;
                for (int kk = 0; kk < trang.size(); kk++) {
                    int k = trang[kk];
                    if (touched[k] || (k%j != posdog%j))
                        continue;
                    found = true;
                    targ = k;
                }

                if (found) {
                    Worst_AddLoc(bads, posdog, kMaxPow);
                    posdog = targ;
                    dogeposes.push_back(make_pair(posdog, j));
                    doglocs.push_back(posdog);
                    bak = 1-bak;
                    touched[posdog] = true;
                    break;
                }
            }

            if (!found)
                break;
        }

        vector<pair<int, int>> middlemen;
        for (int i = 1; i+1 < dogeposes.size(); i++)
            middlemen.push_back(dogeposes[i]);

        for (int j = 0; j < kMaxN; j++) {
            if (!touched[j])
                middlemen.push_back(make_pair(j, kMaxN-1));
        }

        shuffle(middlemen.begin(), middlemen.end(), mt_rand);
        B.push_back(dogeposes.back().first);
        P.push_back(dogeposes.back().second);
        B.push_back(dogeposes.front().first);
        P.push_back(dogeposes.front().second);
        for (pair<int,int> doge : middlemen) {
            B.push_back(doge.first);
            P.push_back(doge.second);
        }

        N = kMaxN;
        M = (int)B.size();
    }

  void sqrtN(int kMaxN, int minval, int maxval, bool alledges = false)
  {
    B.clear();
    P.clear();
    vector <pair<int,int> > doges;
    vector <bool> bads;
    for (int i = 0; i < kMaxN; i++) {
      bads.push_back(false);
    }

    int badcnt= 0;
    vector <pair<int,int> > values;
    for (int i = minval; i <= maxval; i++) {
      for (int j = 0; j < i; j++) {
        values.push_back(make_pair(i,j));
      }
    }
    shuffle(values.begin(), values.end(), mt_rand);
    for (int k = 0; k < (int) values.size(); k++) {
      int pw = values[k].first;
      int i = values[k].second;
      if ((int)doges.size() == kMaxN-2) {
        break;
      }
      int mycnt = 0;
      for (int j = i; j < kMaxN; j+=pw) {
        if(j >= kMaxN/2) {
          if (!bads[j]) {
            mycnt++;
          }
        }
      }
      if (mycnt + badcnt == kMaxN / 2) {
        continue;
      }
      doges.push_back(make_pair(i,pw));
      for (int j = i; j < kMaxN; j+=pw) {
        if (j >= kMaxN/2) {
          if (!bads[j]) {
            badcnt += 1;
            bads[j] = true;
          }
        }
      }
    }
    pair <int,int> targ;
    if (alledges) {
      targ = make_pair(kMaxN-1, 1);
    } else {
      int j = kMaxN - 1;
      while (j >= 0) {
        if (!bads[j]) {
          targ = make_pair(j, 1);
          break;
        }
        j--;
      }
    }
    shuffle(doges.begin(), doges.end(), mt_rand);
    B.push_back(0);
    P.push_back(1);
    B.push_back(targ.first);
    P.push_back(targ.second);
    for (pair<int,int> doge : doges) {
      B.push_back(doge.first);
      P.push_back(doge.second);
    }
    N = kMaxN;
    M = (int)B.size();
  }

  void lotsOfEdges(int kMaxN, int kMaxM, bool alledges) {
    B.clear();
    P.clear();
    vector <pair<int,int> > doges;
    vector<bool> bads = vector<bool>(kMaxN, false);
    int badcnt = 0;
    for (int pw = 2; pw < kMaxN; pw++) {
      if ((int)doges.size() == kMaxM - 2) {
        break;
      }
      for (int i = 0; i < pw; i++) {
        if ((int)doges.size() == kMaxM - 2) {
          break;
        }
        int mycnt = 0;
        for (int j = i; j < kMaxN; j+=pw) {
          if (!bads[j]) {
            mycnt++;
          }
        }
        if (mycnt + badcnt == kMaxN) {
          continue;
        }
        doges.push_back(make_pair(i, pw));
        for (int j = i; j < kMaxN; j+=pw) {
          if (!bads[j]) {
            badcnt++;
            bads[j] = true;
          }
        }
      }
    }
    pair <int,int> targ;
    if (alledges) {
      targ = make_pair(kMaxN-1, 1);
    } else {
      int j = kMaxN - 1;
      while (j >= 0) {
        if (!bads[j]) {
          targ = make_pair(j, 1);
          break;
        }
        j--;
      }
    }
    shuffle(doges.begin(), doges.end(), mt_rand);
    B.push_back(0);
    P.push_back(1);
    B.push_back(targ.first);
    P.push_back(targ.second);
    for (pair<int,int> doge : doges) {
      B.push_back(doge.first);
      P.push_back(doge.second);
    }
    N = kMaxN;
    M = (int)B.size();
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
