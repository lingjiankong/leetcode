// ***
//
// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not
// the kth distinct element.
//
// Example 1:
//
// Input: [3,2,1,5,6,4] and k = 2
// Output: 5
//
// Example 2:
//
// Input: [3,2,3,1,2,4,5,5,6] and k = 4
// Output: 4
//
// Note:
// You may assume k is always valid, 1 ≤ k ≤ array's length.
//
// ***
//
// You can sort the array, use std::nth_element, or use priority_queue and this question can be solved in one line.
// However this question tests your knowledge in applying quick sort.
//
// Memorize the logic in quick sort partition (all elements greater than nums[pivot] to one side, all elements less than
// nums[pivot] to the other side). Use the idea of binary search and quick sort to sort the array in *descending* order
// because you want to find the kth *largest* element i.e. Put all elements greater than nums[pivot] to the left and all
// elements less than nums[pivot] to the right. (If you were to find kth *smallest* element, then you can sort the array
// in *ascending* order).

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;

        while (true) {
            int pos = partition(nums, left, right);

            if (pos == k - 1) {
                return nums[pos];
            } else if (pos < k - 1) {
                left = pos + 1;
            } else {
                right = pos;
            }
        }
    }

private:
    // Put all elements greater than nums[pivot] to the left
    // and all elements less than nums[pivot] to the right, return pivot.
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;

        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                // Sort in descending order,
                // all elements to the left of pivot should be greater than the element to the right of pivot.
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) {
                ++l;
            }
            if (nums[r] <= pivot) {
                --r;
            }
        }

        swap(nums[left], nums[r]);

        return r;
    }
};
