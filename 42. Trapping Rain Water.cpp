// think about the wall and water as individual blocks (width = 1). We only consider the amount of water we can fill at that single position

//             *
//             *
//             *                  *
//             *                  *
//         *   *                  *
// *     * *   * *                *
// * *   * *   * * *        *  *  *
// 0 1 2 3 4 5 6 7 8 10 ... 97 98 99
// L                              R

// maintain two pointers left and right, we keep track of the maximum height of left wall and right wall. The amount of water we can fill at certain position is controlled by 1. the height at current position, 2. min(max height of walls to the left, max height of walls to the right)

// let say now L = 0 and R = 99, the first time we enter the while loop, think about height[99] (i.e. height[right]) being very high, say, higher than height[left] at position from 0, 1, 2, 3, 4, 5, then we enter if (height[left] < height[right]) every time, and the amount of water we can fill at position 0 to 5 is completely determined by leftMaxHeight - height[left] (since height[right], which will later become rightMaxHeight, is always greater than leftMaxHeight, height[right] will never be the constraint (i.e. never going to be the shorter edge)).

// Let's say at position 6, height[left] (which is height[6]) becomes super large, larger than current height[right], then the condition height[left] >= height[right] is ture and we enter the else loop. Now, rightMaxHeight becomes height[right] (height[99]), also maxHeightLeft (which will later become height[6]), >= maxHeightRight. The same theory applies and the height[left] now is never going to be the shorter edge, and the amount of water we can fill at on the right is completely determined by rightMaxHeight - height[right].

//The process repeats, L pointer going right, R pointer going left, until they overlap is when we've finished calculating the amount of water we can fill at all positions

// thus, if height[left] < height[right], then also leftMaxHeight < rightMaxHeight, meaning the amount of water we can fill at current height[left] can be determined only using leftMaxHeight - height[left]. Same is true vice versa if height[left] >= height[right]

class Solution {
public:
    int trap(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int leftMaxHeight = 0;
        int rightMaxHeight = 0;

        int total = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                leftMaxHeight = max(leftMaxHeight, height[left]);
                total += leftMaxHeight - height[left];
                ++left;
            } else {
                rightMaxHeight = max(rightMaxHeight, height[right]);
                total += rightMaxHeight - height[right];
                --right;
            }
        }

        return total;
    }
};
