// ***
//
// You have a function printNumber that can be called with an integer parameter and prints it to the console.
//
// For example, calling printNumber(7) prints 7 to the console.
// You are given an instance of the class ZeroEvenOdd that has three functions: zero, even, and odd. The same instance
// of ZeroEvenOdd will be passed to three different threads:
//
// Thread A: calls zero() that should only output 0's.
// Thread B: calls even() that should only output even numbers.
// Thread C: calls odd() that should only output odd numbers.
// Modify the given class to output the series "010203040506..." where the length of the series must be 2n.
//
// Implement the ZeroEvenOdd class:
//
// ZeroEvenOdd(int n) Initializes the object with the number n that represents the numbers that should be printed.
// void zero(printNumber) Calls printNumber to output one zero.
// void even(printNumber) Calls printNumber to output one even number.
// void odd(printNumber) Calls printNumber to output one odd number.
//
//
// Example 1:
//
// Input: n = 2
// Output: "0102"
// Explanation: There are three threads being fired asynchronously.
// One of them calls zero(), the other calls even(), and the last one calls odd().
// "0102" is the correct output.
// Example 2:
//
// Input: n = 5
// Output: "0102030405"
//
//
// Constraints:
//
// 1 <= n <= 1000
//
// ***

class ZeroEvenOdd {
private:
    int n;

    mutex m;

    bool zeroNext = true;
    bool evenNext = false;
    bool oddNext = false;

    int lastNumber = 0;

    condition_variable cvZeroFinished;
    condition_variable cvNumberFinished;

public:
    ZeroEvenOdd(int n) { this->n = n; }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i) {
            unique_lock<mutex> lk(m);
            cvNumberFinished.wait(lk, [this] { return zeroNext; });

            printNumber(0);

            zeroNext = false;
            if (lastNumber % 2 == 0) {
                oddNext = true;
            } else {
                evenNext = true;
            }

            cvZeroFinished.notify_one();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            unique_lock<mutex> lk(m);
            cvZeroFinished.wait(lk, [this] { return evenNext; });

            printNumber(i);

            lastNumber = i;
            evenNext = false;
            zeroNext = true;

            cvNumberFinished.notify_one();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            unique_lock<mutex> lk(m);
            cvZeroFinished.wait(lk, [this] { return oddNext; });

            printNumber(i);

            lastNumber = i;
            oddNext = false;
            zeroNext = true;

            cvNumberFinished.notify_one();
        }
    }
};
