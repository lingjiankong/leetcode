// ***
//
// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next
// greater number for every element in nums.
//
// The next greater number of a number x is the first greater number to its traversing-order next in the array, which
// means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
//
//
// Example 1:
//
// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2;
// The number 2 can't find next greater number.
// The second 1's next greater number needs to search circularly, which is also 2.
// Example 2:
//
// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]
//
//
// Constraints:
//
// 1 <= nums.length <= 104
// -109 <= nums[i] <= 109
//
// ***

// Monotonic decreasing stack.
//
// This would be the solution if we are not dealing with a circular array. Read this one first.
//
// Traverse nums from *right to left*, pop all elements which are shorter than nums[i] from the stack.
// The top of the remaining stack would be the value of next greater number of nums[i].
// Push nums[i] to the stack and continue traversing left.
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> res(n);
        stack<int> s;

        for (int i = n - 1; i >= 0; --i) {
            while (not s.empty() and s.top() <= nums[i]) {
                s.pop();
            }
            res[i] = s.empty() ? -1 : s.top();
            s.push(nums[i]);
        }

        return res;
    }
};

// Solution to this question. Traverse nums twice since the question says we are given a circular array.
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> res(n);
        stack<int> s;

        for (int i = n * 2 - 1; i >= 0; --i) {
            while (not s.empty() and s.top() <= nums[i % n]) {
                s.pop();
            }
            res[i % n] = s.empty() ? -1 : s.top();
            s.push(nums[i % n]);
        }

        return res;
    }
};

