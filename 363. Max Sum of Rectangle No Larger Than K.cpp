// ***
//
// Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum
// is no larger than k.
//
// Example:
//
// Input: matrix = [[1,0,1],[0,-2,3]], k = 2
// Output: 2
// Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is 2,
//              and 2 is the max number no larger than k (k = 2).
// Note:
//
// The rectangle inside the matrix must have an area > 0.
// What if the number of rows is much larger than the number of columns?
//
// ***
//
// You can decouple this problem into two parts:
// Reduce the 2D matrix to bunch of 1D arrays, and asking each 1D array:
// What is the maximum contiguous subarray which sum is no larger than k?
//
// You need to memorize how to solve this problem.
// The solution is very straightfoward once you understand it.
// It is hard to explain in words. Read the code and google YouTube videos.
//
// l   r
// v   v
// 1 2 3 4     6  < j
// 2 3 4 5     9
// 3 4 5 6     12
// -------     --
//  matrix     sumArray
//
// See also 53. Maximum Subarray, which finds the maximum contiguous subarray (without the constraint from K) using
// dynamic programming
//
//
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int maxSum = INT_MIN;

        // Part 1: decouple the 2D matrix into bunch of 1D problems.
        for (int r = 0; r < matrix[0].size(); ++r) {
            vector<int> sumArray(matrix.size());
            for (int l = r; l < matrix[0].size(); ++l) {
                for (int j = 0; j < matrix.size(); ++j) {
                    sumArray[j] += matrix[j][l];
                }

                // Part 2: find the maximum sum that is no more than K.
                int currentSum = 0;
                set<int> currentSums({0});
                for (auto num : sumArray) {
                    currentSum += num;
                    auto itr = currentSums.lower_bound(currentSum - k);
                    if (itr != currentSums.end()) {
                        maxSum = max(maxSum, currentSum - *itr);
                    }
                    currentSums.insert(currentSum);
                }
            }
        }

        return maxSum;
    }
};

