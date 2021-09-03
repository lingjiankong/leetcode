// ***
//
// In an array A containing only 0s and 1s, a K-bit flip consists of choosing a (contiguous) subarray of length K and
// simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.
//
// Return the minimum number of K-bit flips required so that there is no 0 in the array.  If it is not possible, return
// -1.
//
//
// Example 1:
//
// Input: A = [0,1,0], K = 1
// Output: 2
// Explanation: Flip A[0], then flip A[2].
//
//
// Example 2:
//
// Input: A = [1,1,0], K = 2
// Output: -1
//
// Explanation: No matter how we flip subarrays of size 2, we can't make the array become [1,1,1].
//
//
// Example 3:
//
// Input: A = [0,0,0,1,0,1,1,0], K = 3
// Output: 3
//
// Explanation:
// Flip A[0],A[1],A[2]: A becomes [1,1,1,1,0,1,1,0]
// Flip A[4],A[5],A[6]: A becomes [1,1,1,1,1,0,0,0]
// Flip A[5],A[6],A[7]: A becomes [1,1,1,1,1,1,1,1]
//
// ***
//
// Hard to explain in words but once you understand what happens it is very intuitive.

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int res = 0, n = A.size();

        // Whether the net effect of all previous flips you've done so far have flipped A[i] (the current value you are
        // looking at when you are in the loop). This is used to update isFlipped[i].
        int isCurFlipped = 0;

        // Whether A[i] has actually been flipped.
        vector<int> isFlipped(n);

        for (int i = 0; i < n; ++i) {
            // Each flip will only affect a window of K subsequent elements, so once your window moves right,
            // you should undo the effect before you enter the window.
            if (i >= K) {
                isCurFlipped ^= isFlipped[i - K];
            }

            // While traversing A,
            // See if we need to flip everything in [i, i + K]
            //
            // If isCurFlipped == 0 and A[i] == 0, you need to flip A[i] from 0 to 1.
            // If isCurFlipped == 1 and A[i] == 1, meaning although A[i] was originally 1, it has been flipped to 0, in
            // which case you need to flip A[i] from 0 to 1.
            if (isCurFlipped ^ A[i] == 0) {
                // In this case, it is not possible to flip K consecutive elements from i.
                if (i + K > n) {
                    return -1;
                }
                isFlipped[i] = 1;
                isCurFlipped ^= 1;
                ++res;
            }
        }

        return res;
    }
};

// Similar idea. Use a queue to store the *indexes* of the elements which have been flipped.
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int res = 0, n = A.size();
        queue<int> q;

        for (int i = 0; i < n; ++i) {
            if (not q.empty() and q.front() <= i - K) {
                q.pop();
            }

            // If queue size is even and A[i] == 0 (A[i] was originally 0 and is still 0 after even number of flips),
            // you need to flip A[i] from 0 to 1;
            //
            // If queue size is odd and A[i] == 1 (A[i] was originally 0 but have been filpped from 0 to 1 after odd
            // number of flips), meaning although A[i] was originally 1, it has been flipped to 0, so you need to flip
            // A[i] from 0 back to 1 again.
            if (q.size() % 2 == A[i]) {
                if (i + K > n) {
                    return -1;
                }
                q.push(i);
                ++res;
            }
        }

        return res;
    }
};

