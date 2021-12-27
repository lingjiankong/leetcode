// ***
//
// Given an array of positive integers "nums" and an integer target.
// You have to find two **non-overlapping** sub-arrays of "nums" each with a sum equal to target. 
// There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is minimum.
// Return the minimum sum of the lengths of the two required sub-arrays, or return -1 if you cannot find such two sub-arrays.
//
// Important notes: 
// 1. all integers in "nums" are **positive**
// 2. a sub-arrays is an array within another array which contains **contiguous** elements whereas sub-sequence is not
//
// Example 1:
// Input: nums = [7, 3, 4, 7], target = 7
// Output: 2
// Explanation: There are three sub-arrays with sum = 7 ([7], [3, 4] and [7]). The shortest two are [7] and [7] and the total length is 2.
//
// Example 2:
// Input: nums = [1, 6, 1], target = 7
// Output: -1
// Explanation: We have two one sub-arrays of sum = 7, but they overlap with each other, so we can't find a answer and need to return -1.
//
// ***

#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int getMinSumOfLen(const vector<int>& nums, int target) {
    // prefix sum : index
    unordered_map<int, int> presum2idx;
    presum2idx[0] = -1;

    // index : min len of subarray-sum-to-target that ends *up to* index
    unordered_map<int, int> idx2minlen;

    int ans = SHRT_MAX;
    int minlen = SHRT_MAX;
    int prefixSum = 0;
    for (size_t right = 0; right < nums.size(); ++right) {
        prefixSum += nums[right];
        presum2idx[prefixSum] = right;

        // only update minlen if you are able to find a valid subarray-sum-to-target
        if (presum2idx.count(prefixSum - target)) {
            int left = presum2idx[prefixSum - target];
            int curlen = right - left;
            minlen = min(minlen, curlen);

            // You can only update ans if you are able find idx2minlen[left].
            // That is, you want to find the min subarray-sum-to-target between [0, left) and [left, right].
            // (index might be off. Just get the idea).
            if (idx2minlen.count(left)) {
                ans = min(ans, curlen + idx2minlen[left]);
            }
        }

        // update idx2minlen[right] for every "right" because
        // indx2minlen is the min len of subarray-sum-to-target up to "right"
        idx2minlen[right] = minlen;
    }

    return ans == SHRT_MAX ? -1 : ans;
}

int main() {
    assert(-1 == getMinSumOfLen({1, 6, 1}, 7));
    assert(2 == getMinSumOfLen({7, 3, 4, 7}, 7));
    assert(3 == getMinSumOfLen({3, 1, 1, 1, 5, 1, 2, 1}, 3));

    return 0;
}

