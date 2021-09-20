// ***
//
// Given an array of integers arr, sort the array by performing a series of pancake flips.
//
// In one pancake flip we do the following steps:
//
// Choose an integer k where 1 <= k <= arr.length.
// Reverse the sub-array arr[0...k-1] (0-indexed).
// For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, we reverse the sub-array [3,2,1], so
// arr = [1,2,3,4] after the pancake flip at k = 3.
//
// Return an array of the k-values corresponding to a sequence of pancake flips that sort arr. Any valid answer that
// sorts the array within 10 * arr.length flips will be judged as correct.
//
//
// Example 1:
//
// Input: arr = [3,2,4,1]
// Output: [4,2,4,3]
// Explanation:
// We perform 4 pancake flips, with k values 4, 2, 4, and 3.
// Starting state: arr = [3, 2, 4, 1]
// After 1st flip (k = 4): arr = [1, 4, 2, 3]
// After 2nd flip (k = 2): arr = [4, 1, 2, 3]
// After 3rd flip (k = 4): arr = [3, 2, 1, 4]
// After 4th flip (k = 3): arr = [1, 2, 3, 4], which is sorted.
//
//
// Example 2:
//
// Input: arr = [1,2,3]
// Output: []
// Explanation: The input is already sorted, so there is no need to flip anything.
// Note that other answers, such as [3, 3], would also be accepted.
//
// ***

class Solution {
public:
    vector<int> pancakeSort(vector<int>& cakes) {
        pancakeSort(cakes, cakes.size() - 1);

        return _flips;
    }

private:
    // Flips everything in cacke[0:n]
    void pancakeSort(vector<int>& cakes, int n) {
        // Only one pancake left, no need to flip
        if (n == 0) {
            return;
        }

        int maxCake = 0;
        int maxCakeIdx = 0;
        for (int i = 0; i <= n; ++i) {
            if (cakes[i] > maxCake) {
                maxCake = cakes[i];
                maxCakeIdx = i;
            }
        }

        // Note that std::reverse takes [i, j), therefore needs + 1 on the right index.
        // first, move the max cake to the front
        // then, move max cake to the right
        //
        // example: n = 4 (7, 8, 9 are at their correct spots now)
        //
        // 4 2 6 1 3 7 8 9
        //     ^
        //  maxCake
        //
        // 6 2 4 1 3 7 8 9
        //
        // 3 1 4 4 6 7 8 9 (6, 7, 8, 9 are at their correct spots now,
        // now recursively calling the front of remaining cakes)
        reverse(cakes.begin(), cakes.begin() + maxCakeIdx + 1);
        _flips.push_back(maxCakeIdx + 1);
        reverse(cakes.begin(), cakes.begin() + n + 1);
        _flips.push_back(n + 1);

        pancakeSort(cakes, n - 1);
    }

    vector<int> _flips;
};

