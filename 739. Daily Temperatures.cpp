// ***
//
// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i]
// is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for
// which this is possible, keep answer[i] == 0 instead.
//
//
// Example 1:
//
// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
//
// Example 2:
//
// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
//
// Example 3:
//
// Input: temperatures = [30,60,90]
// Output: [1,1,0]
//
//
// Constraints:
//
// 1 <= temperatures.length <= 105
// 30 <= temperatures[i] <= 100
//
// ***

// Almost exactly the same as 503. Next Greater Element II.
// In this question, the monotonic decreasing stack stores index instead of numbers.
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> res(n);
        stack<int> s;

        for (int i = n - 1; i >= 0; i--) {
            while (not s.empty() and temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }
            res[i] = s.empty() ? 0 : s.top() - i;

            s.push(i);
        }

        return res;
    }
};
