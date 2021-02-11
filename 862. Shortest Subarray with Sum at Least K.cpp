// ***
//
// Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.
//
// If there is no non-empty subarray with sum at least K, return -1.
//
// Example 1:
//
// Input: A = [1], K = 1
// Output: 1
// Example 2:
//
// Input: A = [1,2], K = 4
// Output: -1
// Example 3:
//
// Input: A = [2,-1,2], K = 3
// Output: 3
//
//
// Note:
//
// 1 <= A.length <= 50000
// -10 ^ 5 <= A[i] <= 10 ^ 5
// 1 <= K <= 10 ^ 9
//
// ***
//
// Didn't fully understand. Don't spend too much time on it if you can't get it.

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int shortestLength = INT_MAX, runningSum = 0;

        // Priority queue of runningSum : index, with smallest runningSum having the highest priority.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < A.size(); ++i) {
            runningSum += A[i];

            // This is needed here to capture the case such as shortestLength = A.size().
            if (runningSum >= K) {
                shortestLength = min(shortestLength, i + 1);
            }

            while (!pq.empty() && runningSum - pq.top().first >= K) {
                shortestLength = min(shortestLength, i - pq.top().second);
                pq.pop();  // Didn't understand why pq.pop() is needed here.
            }

            pq.push({runningSum, i});
        }

        return shortestLength == INT_MAX ? -1 : shortestLength;
    }
};

// Same idea as priority queue but using a tree map.
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        map<int, int> runningSumToIndex;
        vector<int> runningSum(A.size() + 1);
        int shortestLength = INT_MAX;

        for (int i = 1; i <= A.size(); ++i) {
            runningSum[i] = runningSum[i - 1] + A[i - 1];
        }

        for (int i = 0; i < runningSum.size(); ++i) {
            // Note that runningSumToIndex is sorted.
            // searchEndPos is the position of the first element in runningSumToIndex such that
            // searchEndPos->first > runningSum[i] - K.
            auto searchEndPos = runningSumToIndex.upper_bound(runningSum[i] - K);
            for (auto itr = runningSumToIndex.begin(); itr != searchEndPos; ++itr) {
                shortestLength = min(shortestLength, i - itr->second);
            }

            runningSumToIndex.erase(runningSumToIndex.begin(),
                                    searchEndPos);  // Didn't understand why erase is needed here.

            runningSumToIndex[runningSum[i]] = i;
        }

        return shortestLength == INT_MAX ? -1 : shortestLength;
    }
};

// Kind of like a squeezing sliding window idea.
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int shortestLength = INT_MAX;

        // Stores the running sum of A. For example,
        // A = [84, -37, 32, 40, 95]
        // sum = [0, 84, 47, 79, 119, 214]
        vector<int> sums(A.size() + 1);
        for (int i = 1; i <= A.size(); ++i) {
            sums[i] = sums[i - 1] + A[i - 1];
        }

        // Stores the indexes of A
        deque<int> dq;

        for (int i = 0; i <= A.size(); ++i) {
            while (!dq.empty() && sums[i] - sums[dq.front()] >= K) {
                // In this case, there is a contiguous subarray of A indexed by [dq.front(), i] (inclusive)
                // with sum at least K, we compare shortestLength with current length i - dq.front().
                // We keep popping index from deque and keep comparing in the while loop.
                shortestLength = min(shortestLength, i - dq.front());
                dq.pop_front();
            }

            while (!dq.empty() && sums[i] <= sums[dq.back()]) {
                // It is kind of hard to explain what happens here
                // In this case, we are seeing a longer length but smaller sum because of negative numbers in between.
                // This means dq.back() is a useless index because it does not help us finding the shortest continuous
                // subarray. For exmaple, let's say A = [2, 3, -4, 5, 6], sum = [0, 2, 5, 1, 6, 12]. Currently i = 3 and
                // dq.back() = 2. Now sum[3] = 1, we see that sums[3] <= sums[2] (sums[i] <= sums[dq.back()], 1 <= 5).
                // We will remove index 2 from dq because sums[2] = 5, but we are seeing a smaller sum at sum[3] = 1.
                //
                // Think of it this way: sums[5] - sums[2] = 12 - 5 = 7; sums[5] - sums[3] = 12 - 1 = 11.
                // You can always get a at least as large as sum difference using index on the right (i = 3)
                // than using current dq.back() (i = 2). That's why you pop it because it is useless.
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return shortestLength == INT_MAX ? -1 : shortestLength;
    }
};
