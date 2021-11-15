// ***
//
// Given a binary array data, return the minimum number of swaps required to group all 1’s present in the array together
// in any place in the array.
//
//
// Example 1:
//
// Input: data = [1,0,1,0,1]
// Output: 1
// Explanation:
// There are 3 ways to group all 1's together:
// [1,1,1,0,0] using 1 swap.
// [0,1,1,1,0] using 2 swaps.
// [0,0,1,1,1] using 1 swap.
// The minimum is 1.
//
//
// Example 2:
//
// Input: data = [0,0,0,1,0]
// Output: 0
// Explanation:
// Since there is only one 1 in the array, no swaps needed.
//
//
// Example 3:
//
// Input: data = [1,0,1,0,1,0,0,1,1,0,1]
// Output: 3
// Explanation:
// One possible solution that uses 3 swaps is [0,0,0,0,0,1,1,1,1,1,1].
//
//
// Example 4:
//
// Input: data = [1,0,1,0,1,0,1,1,1,0,1,0,0,1,1,1,0,0,1,1,1,0,1,0,1,1,0,0,0,1,1,1,1,0,0,1]
// Output: 8
//
// ***

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int totalOnes = accumulate(data.begin(), data.end(), 0);
        int res = INT_MAX;

        int numOnes = 0;
        int left = 0, right = 0;

        while (right < data.size()) {
            int num = data[right++];
            if (num == 1) {
                ++numOnes;
            }

            while (right - left > totalOnes) {
                int num = data[left++];
                if (num == 1) {
                    --numOnes;
                }
            }

            if (right - left == totalOnes) {
                res = min(res, totalOnes - numOnes);
            }
        }

        return res;
    }
};

// Same idea.
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int totalOnes = accumulate(data.begin(), data.end(), 0);
        int res = INT_MAX;

        vector<int> window(2, 0);
        int left = 0, right = 0;

        while (right < data.size()) {
            int num = data[right++];
            ++window[num];

            while (window[0] + window[1] > totalOnes) {
                int num = data[left++];
                --window[num];
            }

            if (window[0] + window[1] == totalOnes) {
                res = min(res, window[0]);
            }
        }

        return res;
    }
};

// Same idea.
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int totalOnes = accumulate(data.begin(), data.end(), 0);
        int res = INT_MAX;

        vector<int> window(2, 0);
        int left = 0, right = 0;

        while (right < data.size()) {
            int num = data[right++];
            ++window[num];

            while (window[0] + window[1] == totalOnes) {
                res = min(res, window[0]);
                int num = data[left++];
                --window[num];
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};
