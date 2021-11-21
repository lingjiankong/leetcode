// ***
//
// Suppose you are given the following code:
//
// class FooBar {
//   public void foo() {
//     for (int i = 0; i < n; i++) {
//       print("foo");
//     }
//   }
//
//   public void bar() {
//     for (int i = 0; i < n; i++) {
//       print("bar");
//     }
//   }
// }
// The same instance of FooBar will be passed to two different threads:
//
// thread A will call foo(), while
// thread B will call bar().
// Modify the given program to output "foobar" n times.
//
//
//
// Example 1:
//
// Input: n = 1
// Output: "foobar"
// Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
// "foobar" is being output 1 time.
// Example 2:
//
// Input: n = 2
// Output: "foobarfoobar"
// Explanation: "foobar" is being output 2 times.
//
//
// Constraints:
//
// 1 <= n <= 1000
//
// ***

class FooBar {
private:
    int n;

    mutex m;

    bool printFooNext = true;  // if true, should print Foo next; if false, should print Bar next.
    condition_variable cvFooFinished;
    condition_variable cvBarFinished;

public:
    FooBar(int n) { this->n = n; }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(m);

            cvBarFinished.wait(lk, [this] { return printFooNext; });

            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();

            printFooNext = false;
            cvFooFinished.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(m);

            cvFooFinished.wait(lk, [this] { return not printFooNext; });

            // printBar() outputs "bar". Do not change or remove this line.
            printBar();

            printFooNext = true;
            cvBarFinished.notify_one();
        }
    }
};
