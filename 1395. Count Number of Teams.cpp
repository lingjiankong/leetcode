// ***
//
// There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
//
// You have to form a team of 3 soldiers amongst them under the following rules:
//
// Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
// A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k
// < n). Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).
//
//
// Example 1:
//
// Input: rating = [2,5,3,4,1]
// Output: 3
// Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1).
//
//
// Example 2:
//
// Input: rating = [2,1,3]
// Output: 0
// Explanation: We can't form any team given the conditions.
//
//
// Example 3:
//
// Input: rating = [1,2,3,4]
// Output: 4
//
//
// Constraints:
//
// n == rating.length
// 3 <= n <= 1000
// 1 <= rating[i] <= 10^5
// All the integers in rating are unique.
//
// ***
//
// Note that in this question, each soldier can be part of multiple teams.

// Brute force. TLE.
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        for (int i = 0; i < rating.size() - 2; ++i) {
            for (int j = i + 1; j < rating.size() - 1; ++j) {
                for (int k = j + 1; k < rating.size(); ++k) {
                    if ((rating[i] < rating[j] and rating[j] < rating[k]) or
                        (rating[i] > rating[j] and rating[j] > rating[k])) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        for (int j = 0; j < rating.size(); ++j) {
            int l = 0;  // number of elements that are less than rating[j] in [0, j)
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) {
                    ++l;
                }
            }

            int r = 0;  // number of elements that are greater than rating[j] in (j, n)
            for (int k = j + 1; k < rating.size(); ++k) {
                if (rating[j] < rating[k]) {
                    ++r;
                }
            }
            // l * r: number of tuples such that rating[i] < rating[j] < rating[k]
            // (j - l) * (rating.size() - j - 1 - r): number of tuples such that rating[i] > rating[j] > rating[k]
            ans += l * r + (j - l) * (rating.size() - j - 1 - r);
        }
        return ans;
    }
};
