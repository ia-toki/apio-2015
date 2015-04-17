#include "tcframe/tcframe.hpp"
using namespace tcframe;

#include <vector>
#include <random>
#include <algorithm>
using namespace std;

class Problem : public BaseProblem {
protected:
    int N, A, B;
    vector<int> D;

    int result;

    void Config() {
        setSlug("partition");
    }

    void InputFormat() {
        LINE(N, A, B);
        LINE(D % SIZE(N));
    }

    void OutputFormat() {
        LINE(result);
    }

    void Subtask1() {
        CONS(1 <= N && N <= 20);
        CONS(1 <= A && A <= B && B <= N);
        CONS(eachElementBetween(D, 0, 1000000000));
    }

    void Subtask2() {
        CONS(1 <= N && N <= 50);
        CONS(1 <= A && A <= B && B <= min(20,N));
        CONS(eachElementBetween(D, 0, 10));
    }

    void Subtask3() {
        CONS(1 <= N && N <= 100);
        CONS(A == 1);
        CONS(1 <= B && B <= N);
        CONS(eachElementBetween(D, 0, 20));
    }

    void Subtask4() {
        CONS(1 <= N && N <= 100);
        CONS(1 <= A && A <= B && B <= N);
        CONS(eachElementBetween(D, 0, 1000000000));
    }

    void Subtask5() {
        CONS(1 <= N && N <= 1000);
        CONS(A == 1);
        CONS(1 <= B && B <= N);
        CONS(eachElementBetween(D, 0, 1000000000));
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
            "5 1 2",
            "0 1 5 3 4"
        }, {1 ,2, 3, 4, 5});
    }

    void TestGroup1() { 
        //1 <= N <= 20
        //A = 1, 1 <= B <= N
        //0 <= D[i] <= 10
        assignToSubtasks({1, 2, 3, 4, 5});

        CASE(N = 1, A = 1, B = 1, randomArray(0,0));
        CASE(N = 5, A = 1, B = 3, randomArray(0,10));
        CASE(N = 10, A = 1, B = 1, randomArray(0,10));
        CASE(N = 15, A = 1, B = 15, randomArray(0,10));
        CASE(N = 17, A = 1, B = 3, randomArray(0,10));
        CASE(N = 20, A = 1, B = 3, randomArray(0,10));
    }

    void TestGroup2() {
        //1 <= N <= 20
        //1 <= A <= B <= N
        //0 <= D[i] <= 10
        assignToSubtasks({1, 2, 4});

        CASE(N = 5, A = 2, B = 3, randomArray(0,10));
        CASE(N = 10, A = 2, B = 4, randomArray(0,10));
        CASE(N = 15, A = 15, B = 15, randomArray(0,10));
        CASE(N = 17, A = 3, B = 3, randomArray(0,10));
        CASE(N = 20, A = 4, B = 7, randomArray(0,10));
    }

    void TestGroup3() {
        //1 <= N <= 20
        //A = 1, 1 <= B <= N
        //0 <= D[i] <= 1000000000
        assignToSubtasks({1, 4, 5});

        CASE(N = 5, A = 1, B = 3, randomArray(0,1000000000));
        CASE(N = 10, A = 1, B = 4, randomArray(0,1000000000));
        CASE(N = 13, A = 1, B = 13, randomArray(0,1000000000));
        CASE(N = 19, A = 1, B = 3, randomArray(0,1000000000));
        CASE(N = 20, A = 1, B = 7, randomArray(0,1000000000));
    }

    void TestGroup4() {
        //1 <= N <= 50
        //A = 1, 1 <= B <= min(20,N)
        //0 <= D[i] <= 10
        assignToSubtasks({2, 3, 4, 5});

        CASE(N = 21, A = 1, B = 20, randomArray(0,10));
        CASE(N = 25, A = 1, B = 10, randomArray(0,10));
        CASE(N = 38, A = 1, B = 5, randomArray(0,10));
        CASE(N = 42, A = 1, B = 18, randomArray(0,10));
        CASE(N = 50, A = 1, B = 20, randomArray(0,10));
    }

    void TestGroup5() {
        //1 <= N <= 100
        //A = 1, 1 <= B <= N
        //0 <= D[i] <= 20
        assignToSubtasks({3, 4, 5});

        CASE(N = 51, A = 1, B = 20, randomArray(0,20));
        CASE(N = 65, A = 1, B = 10, randomArray(0,20));
        CASE(N = 78, A = 1, B = 23, randomArray(0,20));
        CASE(N = 91, A = 1, B = 55, randomArray(0,20));
        CASE(N = 100, A = 1, B = 100, randomArray(0,20));
    }

    void TestGroup6() {
        //1 <= N <= 100
        //A = 1, 1 <= B <= N
        //0 <= D[i] <= 1000000000
        assignToSubtasks({4, 5});

        CASE(N = 51, A = 1, B = 20, randomArray(0,1000000000));
        CASE(N = 65, A = 1, B = 10, randomArray(0,1000000000));
        CASE(N = 78, A = 1, B = 23, randomArray(0,1000000000));
        CASE(N = 91, A = 1, B = 55, randomArray(0,1000000000));
        CASE(N = 100, A = 1, B = 100, randomArray(0,1000000000));
    }

    void TestGroup7() {
        //1 <= N <= 100
        //1 <= A <= B <= N
        //0 <= D[i] <= 1000000000
        assignToSubtasks({4});

        CASE(N = 51, A = 11, B = 20, randomArray(0,1000000000));
        CASE(N = 65, A = 2, B = 10, randomArray(0,1000000000));
        CASE(N = 78, A = 2, B = 23, randomArray(0,1000000000));
        CASE(N = 91, A = 19, B = 55, randomArray(0,1000000000));
        CASE(N = 100, A = 57, B = 100, randomArray(0,1000000000));
    }

    void TestGroup8() {
        //1 <= N <= 1000
        //A = 1, 1 <= B <= N
        //0 <= D[i] <= 1000000000
        assignToSubtasks({5});

        CASE(N = 101, A = 1, B = 20, randomArray(0,1000000000));
        CASE(N = 244, A = 1, B = 56, randomArray(0,1000000000));
        CASE(N = 404, A = 1, B = 400, randomArray(0,1000000000));
        CASE(N = 575, A = 1, B = 99, randomArray(0,1000000000));
        CASE(N = 747, A = 1, B = 747, randomArray(0,1000000000));
        CASE(N = 999, A = 1, B = 20, randomArray(0,1000000000));
        CASE(N = 1000, A = 1, B = 1, randomArray(0,1000000000));
        CASE(N = 1000, A = 1, B = 55, randomArray(0,1000000000));
        CASE(N = 1000, A = 1, B = 1000, randomArray(0,1000000000));
    }

private:
    mt19937 mt_rand; // Mersenne Twister pseudo-random generator
    int varA, varB, varN;

    void randomArray(int minValue, int maxValue) {
        D.clear(); // important!
        for (int i = 0; i < N; i++) {
            D.push_back(randomIntBetween(minValue,maxValue));
        }
    }

    int randomIntBetween(int minValue,int maxValue) {
        uniform_int_distribution<int> dist(minValue, maxValue);
        return dist(mt_rand);
    }

    void assignFromVar() {
        N = varN;
        A = varA;
        B = varB;
    }
};

int main() {
    Generator gen;
    return gen.generate();
}
