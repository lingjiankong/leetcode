// binary search is a O(nlogn), there's another O(n) method that uses the idea in linked list cycle. You can do that if you have time in the future

// nums is unsorted, but we show sorted nums for clarity. Our algorithm works with unsorted nums
// note that we are guaranteed that there is only one duplicate number in the array, but it could be repeated more than once.

// first mid = 5
// no duplicate in [1, 5]
// nums  [1 2 3 4 5 6 8 8 8 10 11]
// index [0 1 2 3 4 5 6 7 8 9  10]
//
// duplicate in [1, 5]
// nums  [1 3 3 3 5 6 7 8 9 10 11]
// index [0 1 2 3 4 5 6 7 8 9  10]

// every time you calculate a new mid, you iterate through all nums and find how many elements are less than or equal to mid, and store it in count. If there's no duplicate before mid (i.e. in [1, mid]), then there should be exactly mid elements in nums that <= mid (i.e. count = mid -> in the first example, mid = 5, count = len([1, 2, 3, 4, 5]) = 5 = mid). If there is duplicate in [1, mid], then count > mid, duplicate must be in [1, m], hence mid = high-1 in this case.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            int count = 0;
            for (int num : nums) {
                if (num <= mid)
                    ++count;
            }
            if (count > mid)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
