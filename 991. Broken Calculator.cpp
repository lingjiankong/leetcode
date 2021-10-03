// ***
//
// There is a broken calculator that has the integer startValue on its display initially. In one operation you can:
//
// multiply the number on the display by 2, or
// subtract 1 from the number on the display.
// Given two integers startValue and target, return the minimum number of operations needed to display target on the
// calculator.
//
//
// Example 1:
//
// Input: startValue = 2, target = 3
// Output: 2
// Explanation: Use double operation and then decrement operation {2 -> 4 -> 3}.
//
//
// Example 2:
//
// Input: startValue = 5, target = 8
// Output: 2
// Explanation: Use decrement and then double {5 -> 4 -> 8}.
//
//
// Example 3:
//
// Input: startValue = 3, target = 10
// Output: 3
// Explanation: Use double, decrement and double {3 -> 6 -> 5 -> 10}.
//
//
// Example 4:
//
// Input: startValue = 1024, target = 1
// Output: 1023
// Explanation: Use decrement operations 1023 times.
//
// ***

// dp[i] minimum number of operations to display i on the calculator
//
// Base conditions:
// dp[startValue] = 0
//
// dp[startValue - 1] = dp[startValue] + 1
// dp[startValue * 2] = dp[startValue] + 1

// The idea is very simple. Moving target towards startValue.
// (multiplication on displayed value becomes devision on target;
// substraction from the displayed value becomes addition to target)
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int res = 0;

        while (target > startValue) {
            if (target % 2 == 0) {  // if target is even, devide it by two
                target /= 2;
            } else {
                target += 1;  // if target is odd, add one to it (so we can devide it by two later)
            }
            ++res;
        }

        // once target <= startValue, we can only do addition on target to bring target closer to startValue.
        int remaining = startValue - target;

        return res + remaining;
    }
};

// Same idea, recursion.
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if (target <= startValue) {
            return startValue - target;
        }

        return target % 2 == 0 ? 1 + brokenCalc(startValue, target / 2) : 1 + brokenCalc(startValue, target + 1);
    }
};
