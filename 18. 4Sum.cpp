// ***
//
// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b +
// c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
// Note:
//
// The solution set must not contain duplicate quadruplets.
//
// Example:
//
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]
//
// ***

// Generalization: n sum. See labuladong book pp. 326.
// In this solution, we eliminate duplicate element in the end instead of from the beginning,
// which can be cleaner.
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Do not forget to sort the array first in these types of problems!
        sort(nums.begin(), nums.end());

        int n = 4, start = 0;
        return nSum(n, nums, start, target);
    }

private:
    vector<vector<int>> nSum(int n, const vector<int>& nums, int start, int target) {
        if (n == 2) {
            return twoSum(nums, start, target);
        }

        vector<vector<int>> res;
        for (int i = start; i < nums.size(); ++i) {
            vector<vector<int>> subs = nSum(n - 1, nums, i + 1, target - nums[i]);
            for (vector<int>& sub : subs) {
                sub.push_back(nums[i]);
                res.push_back(sub);
            }

            // Skip duplicate element.
            while (i < nums.size() - 1 and nums[i] == nums[i + 1]) {
                ++i;
            }
        }

        return res;
    }

    vector<vector<int>> twoSum(const vector<int>& nums, int start, int target) {
        vector<vector<int>> res;
        int left = start, right = nums.size() - 1;
        while (left < right) {
            int leftVal = nums[left], rightVal = nums[right];
            int sum = leftVal + rightVal;
            if (sum == target) {
                res.push_back({leftVal, rightVal});
                while (left < right and leftVal == nums[left]) {
                    ++left;
                }
                while (left < right and rightVal == nums[right]) {
                    --right;
                }
            } else if (sum < target) {
                while (left < right and leftVal == nums[left]) {
                    ++left;
                }
            } else if (sum > target) {
                while (left < right and rightVal == nums[right]) {
                    --right;
                }
            }
        }
        return res;
    }
};

// See also 15. 3Sum. Same idea. This question just add one more for loop.
// Read this question before you read 15. 3Sum.
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> allPairs;

    sort(nums.begin(), nums.end());

    // Find the first candidate element.
    for (int i = 0; i < nums.size() - 3; ++i) {
        // Remove duplicate elements. Don't forget.
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        // Find the second candidate element.
        for (int j = i + 1; j < nums.size() - 2; ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }

            // Find the third and fourth candidate elements.
            int left = j + 1, right = nums.size() - 1;
            while (left < right) {
                int leftVal = nums[left], rightVal = nums[right];
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    allPairs.push_back({nums[i], nums[j], leftVal, rightVal});
                    while (left < right && leftVal == nums[left]) {
                        ++left;
                    }
                    while (left < right && rightVal == nums[right]) {
                        --right;
                    }
                } else if (sum < target) {
                    while (left < right && leftVal == nums[left]) {
                        ++left;
                    }
                } else if (sum > target) {
                    while (left < right && rightVal == nums[right]) {
                        --right;
                    }
                }
            }
        }
    }

    return allPairs;
}

