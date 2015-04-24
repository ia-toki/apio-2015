#include "tcframe/tcframe.hpp"
using namespace tcframe;

#include <vector>
#include <random>
#include <algorithm>
#include <assert.h>
using namespace std;

class Problem : public BaseProblem {
protected:
    int K, N;
    vector<char> TS, TE;
    vector<int> PS, PE;

    long long result;

    void Config() {
        setSlug("bridge");
    }

    void InputFormat() {
        LINE(K, N);
        LINES(TS, PS, TE, PE) % SIZE(N);
    }

    void OutputFormat() {
        LINE(result);
    }

    void commonConstraint() {
        CONS(eachElementBetween(TS, 'A', 'B'));
        CONS(eachElementBetween(TE, 'A', 'B'));
        CONS(eachElementBetween(PS, 0, 1000000000));
        CONS(eachElementBetween(PE, 0, 1000000000));
    }

    void Subtask1() {
        commonConstraint();
        CONS(K == 1);
        CONS(1 <= N && N <= 1000);
    }

    void Subtask2() {
        commonConstraint();
        CONS(K == 1);
        CONS(1 <= N && N <= 100000);
    }

    void Subtask3() {
        commonConstraint();
        CONS(K == 2);
        CONS(1 <= N && N <= 100);
    }

    void Subtask4() {
        commonConstraint();
        CONS(K == 2);
        CONS(1 <= N && N <= 1000);
    }

    void Subtask5() {
        commonConstraint();
        CONS(K == 2);
        CONS(1 <= N && N <= 100000);
    }

private:
    bool eachElementBetween(const vector<int>& A, int lo, int hi) {
        for (int x : A) {
            if (x < lo || x > hi) {
                return false;
            }
        }
        return true;
    }

    bool eachElementBetween(const vector<char>& A, char lo, char hi) {
        for (int x : A) {
            if (x < lo || x > hi) {
                return false;
            }
        }
        return true;
    }
};

class Generator : public BaseGenerator<Problem> {
public:
    Generator() {
        mt_rand = mt19937(477444744);
    }

protected:
    void Config() {
        setBaseDir("tc");
        setSolution("./solution");
    }

    void SampleTestCases() {
        SAMPLE_CASE({
            "1 5",
            "B 0 A 4",
            "B 1 B 3",
            "A 5 B 7",
            "B 2 A 6",
            "B 1 A 7"
        }, {1 ,2});
        SAMPLE_CASE({
            "2 5",
            "B 0 A 4",
            "B 1 B 3",
            "A 5 B 7",
            "B 2 A 6",
            "B 1 A 7"
        }, {3, 4, 5});
    }

    void TestGroup1() { 
        //K = 1
        //1 <= N <= 1000
        assignToSubtasks({1, 2});

        CASE(K = 1, N = 1, makeArray(1000000000));
        CASE(K = 1, N = 4, makeArray(100));
        CASE(K = 1, N = 1000, makeArray(1));
        CASE(K = 1, N = 1000, makeArray(100));
        CASE(K = 1, N = 1000, makeArray(1000000));
        CASE(K = 1, N = 967, makeArray(1000000000));
        CASE(K = 1, N = 1000, makeArray(1000000000));
    }

    void TestGroup2() { 
        //K = 1
        //1 <= N <= 100000
        assignToSubtasks({2});

        CASE(K = 1, N =  100000, makeArray(1));
        CASE(K = 1, N =  100000, makeArray(100));
        CASE(K = 1, N =  100000, makeArray(1000000));
        CASE(K = 1, N =  100000, makeArray(1000000000));
    }

    void TestGroup3() { 
        //K = 2
        //1 <= N <= 100
        assignToSubtasks({3, 4, 5});

        CASE(K = 2, N =  1, makeArray(1000000000));
        CASE(K = 2, N =  4, makeArray(100));
        CASE(K = 2, N =  100, makeArray(1));
        CASE(K = 2, N =  100, makeArray(100));
        CASE(K = 2, N =  100, makeArray(1000000));
        CASE(K = 2, N =  87, makeArray(1000000000));
        CASE(K = 2, N =  100, makeArray(1000000000));
        CASE(K = 2, N =  100, makeArray(1000000000));
    }

    void TestGroup4() { 
        //K = 2
        //1 <= N <= 1000
        assignToSubtasks({4, 5});

        CASE(K = 2, N =  1000, makeArray(1));
        CASE(K = 2, N =  1000, makeArray(100));
        CASE(K = 2, N =  1000, makeArray(10000));
        CASE(K = 2, N =  1000, makeArray(1000000));
        CASE(K = 2, N =  993, makeArray(1000000000));
        CASE(K = 2, N =  958, makeArray(1000000000));
        CASE(K = 2, N =  1000, makeArray(1000000000));
    }

    void TestGroup5() { 
        //K = 2
        //1 <= N <= 100000
        assignToSubtasks({5});

        CASE(K = 2, N =  100000, makeArray(1));
        CASE(K = 2, N =  100000, makeArray(100));
        CASE(K = 2, N =  100000, makeArray(1000000));
        CASE(K = 2, N =  100000, makeArray(1000000000));
    }

private:
    mt19937 mt_rand; // Mersenne Twister pseudo-random generator
    int varA, varB, varN;
    double EPS = 1e-9;

    void makeArray(int mcd) {
        TS.clear(); TE.clear();
        PS.clear(); PE.clear();
        for (int i = 0; i < N; ++i) {
            int fir = randomIntBetween(0,1), sec;
            if (randomIntBetween(0, N - 1) < 10) {
                sec = fir;
            } else {
                sec = 1 - fir;
            }
            TS.push_back((char)(fir + 'A'));
            TE.push_back((char)(sec + 'A'));
            PS.push_back(randomIntBetween(0,mcd));
            PE.push_back(randomIntBetween(0,mcd));
        }
    }

    int randomIntBetween(int minValue,int maxValue) {
        uniform_int_distribution<int> dist(minValue, maxValue);
        return dist(mt_rand);
    }


};

int main() {
    Generator gen;
    return gen.generate();
}
