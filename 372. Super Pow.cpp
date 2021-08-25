// ***
//
// Your task is to calculate a^b mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
// 
//  
// Example 1:
// 
// Input: a = 2, b = [3]
// Output: 8
// Example 2:
// 
// Input: a = 2, b = [1,0]
// Output: 1024
// Example 3:
// 
// Input: a = 1, b = [4,3,3,8,5,2]
// Output: 1
// Example 4:
// 
// Input: a = 2147483647, b = [2,0,0]
// Output: 1198
//  
// 
// Constraints:
// 
// 1 <= a <= 2^31 - 1
// 1 <= b.length <= 2000
// 0 <= b[i] <= 9
// b doesn't contain leading zeros.
//
// ***

// Exotic question. See labuladong book pp. 355.
class Solution {
public: 
    // a^[1,5,6,4] = a^4 * a^[1,5,6,0] = a^4 * (a^[1,5,6])^10
    int superPow(int a, vector<int>& b) {
        if (b.empty()) {
            return 1;
        }

        int last = b.back();
        b.pop_back();

        int part1 = powThenMod(a, last, 1337);
        int part2 = powThenMod(superPow(a, b), 10, 1337);

        return (part1 * part2) % 1337;
    }
private:

    // (a * b) % k = (a % k)(b % k) % k
    //
    // Proof:
    //
    // Assume: a = Ak + B, b = Ck +D
    // Therefore: a % k = B, b % k = D
    //
    // Also: ab = ACk^2 + ADk + BCk + BD
    // Therefore: ab % k = BD % k
    //
    // Hence: (ab) % k = (a % k)(b % k) % k
    //
    // This function calculates num ^ exp % base
    // which is equivalent to ((num % base) * (num % base) * (num % base) * ... [exp times]) % base
    int powThenMod(int num, int exp, int base) {
        num %= base;
        int res = 1;
        while (exp--) {
            res *= num;
            res %= base;
        }
        return res;
    }
};

