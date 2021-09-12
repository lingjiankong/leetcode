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

// You can sort the array, use std::nth_element, or use priority_queue and this question can be solved in one line.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; ++i) {
            pq.pop();
        }
        return pq.top();
    }
};

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
        int pivot = nums[left], l = left + 1;

        // all elements left to "l" are greater than pivot
        //
        // for example, initially you have
        // 5     8     3     1     4     2     3     9     6
        // ^     ^
        // pivot l
        //
        // after the for loop, you have (6789 and 1234 blob might be ordered differently):
        // 5     6     7     8     9     1     2     3     4
        // ^                             ^
        // pivot                         l
        //
        // you want pivot to be in the correct place and return the pivot position.
        // therefore, you need to swap(nums[left], nums[i-1]) and return l - 1
        //
        // 9     6     7     8     5     1     2     3     4
        //                         ^
        //                         pivot
        for (int i = left + 1; i <= right; ++i) {
            if (nums[i] > pivot) {
                swap(nums[i], nums[l++]);
            }
        }

        swap(nums[left], nums[l - 1]);

        return l - 1;
    }
};

// Full quick sort solution, sorted in ascending order
class QuickSort {
public:
    int quickSort(vector<int>& nums) { _quickSort(nums, 0, nums.size() - 1); }

private:
    int _quickSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int pivot = _partition(nums, left, right);
            _quickSort(nums, left, pivot - 1);
            _quickSort(nums, pivot + 1, right);
        }
    }

    int _partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1;
        for (int i = left + 1; i <= right; ++i) {
            if (nums[i] < pivot) {  // to sort in descending order, simply change this to ">"
                swap(nums[i], nums[l++]);
            }
        }

        swap(nums[left], nums[l - 1]);
        return l - 1;
    }
};
