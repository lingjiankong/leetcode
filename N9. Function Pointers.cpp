// ***
// Just a reminder of how to use and pass around function pointers.
//
// ***

#include <functional>
#include <iostream>
#include <string>

using namespace std;

void consumer(string& s1, string& s2, string& s3, std::function<bool(string&, int)> f1, bool (*fp2)(string&, int),
              bool (*fp3)(string&, int)) {
    f1(s1, 1);
    fp2(s2, 2);
    fp3(s3, 3);
}

bool func3(string& s, int num) {
    cout << "[func3] "
         << "received string: " << s << ", num: " << num << endl;
    s = "I am changed inside func3";
    return true;
}

int main() {
    string s1 = "I am given to func1";
    string s2 = "I am given to func2";
    string s3 = "I am given to func3";

    // Using std::function and lambda expression
    std::function<bool(string&, int)> func1 = [](string& s, int num) {
        cout << "[func1] "
             << "received string: " << s << ", num: " << num << endl;
        s = "I am changed inside func1";
        return true;
    };

    // Using function pointer and lambda expression
    bool (*func2Ptr)(string&, int) = [](string& s, int num) {
        cout << "[func2] "
             << "received string: " << s << ", num: " << num << endl;
        s = "I am changed inside func2";
        return true;
    };

    // Using function pointer and point to pre-declared function.
    bool (*func3Ptr)(string&, int) = func3;

    consumer(s1, s2, s3, func1, func2Ptr, func3Ptr);

    cout << "s1 becomes " << s1 << endl;
    cout << "s2 becomes " << s2 << endl;
    cout << "s3 becomes " << s3 << endl;
}

// Expect:
//
// [func1] received string: I am given to func1, num: 1
// [func2] received string: I am given to func2, num: 2
// [func3] received string: I am given to func3, num: 3
//
// s1 becomes I am changed inside func1
// s2 becomes I am changed inside func2
// s3 becomes I am changed inside func3
