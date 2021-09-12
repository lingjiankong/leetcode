// ***
//
// Given an array of size n, find the majority element. The majority element is the element that appears more than
// ⌊ n/2 ⌋ times.
//
// You may assume that the array is non-empty and the majority element always exist in the array.
//
// Example 1:
// Input: [3,2,3]
// Output: 3
//
// Example 2:
// Input: [2,2,1,1,1,2,2]
// Output: 2
//
// ***

// Hash table
int majorityElement(vector<int>& nums) {
    unordered_map<int, int> hash;
    for (int num : nums) {
        if (++hash[num] > nums.size() / 2) {
            return num;
        }
    }
    return -1;
}

// Find the sorted nth element
// std::nth_element(RandomIt first, RandomIt nth, RandomIt last)
// std::nth_element(): rearranges the elements in the range [first,last),
// in such way that the element at the nth position is the element that would be
// in that position in a sorted sequence. The other elements are left without any specific order,
// except that none of the elements preceding nth are greater than it, and none of the elements following it are less.
int majorityElement(vector<int>& nums) {
    nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
    return nums[nums.size() / 2];
}

// Devide and conquer
// Won't be the most efficient one, just get the idea.
class Solution {
public:
    int majorityElement(vector<int>& nums) { return majorityElement(nums, 0, nums.size() - 1); }

private:
    int majorityElement(vector<int>& nums, int l, int r) {
        if (l == r) {
            return nums[l];
        }

        int m = l + (r - l) / 2;
        int leftMajority = majorityElement(nums, l, m);
        int rightMajority = majorityElement(nums, m + 1, r);

        // if nums[l:m] and nums[m+1:r] have the same majority elements,
        // then this element must also be the majority element of nums[l:r]
        if (leftMajority == rightMajority) {
            return leftMajority;
        }

        // Otherwise, the majority element is either leftMajority or rightMajority.
        // We need to maunally count and see which one it is.
        if (count(nums.begin() + l, nums.begin() + r + 1, leftMajority) >
            count(nums.begin() + l, nums.begin() + r + 1, rightMajority)) {
            return leftMajority;
        }
        return rightMajority;
    };
};

// Moore voting alogorithm - a.
// This is exactly the same as 2b. below, just make the algorithm clear so you know what's going on.
//
// Basic idea of the algorithm is if we cancel out each occurrence of an element e with
// all the other elements that are different from e, then e will exist until the end if it is the majority element.
// Code below loops through each element and maintains a count of the element that has the potential of
// being the majority element. If next element is same then increments the count, otherwise decrements the count.
// If the count reaches 0 then update the potential index to the current element and sets count to 1.
int majorityElement(vector<int>& nums) {
    int candidateIdx = 0;  // candidate index for the majority element
    int count = 1;

    for (int i = 1; i < nums.size(); ++i) {
        nums[candidateIdx] == nums[i] ? ++count : --count;

        if (count == 0) {
            candidateIdx = i;
            count = 1;
        }
    }

    return nums[candidateIdx];
}

// Moore voting algorithm - b.
// This is a more generic form, see 229. Majority Element II.
//
// The idea is to repeatedly get rid of pairs of different element,
// after which the element left must be the majority element.
// Note that, in the problem statement, a majority element is guaranteed to exist.
// If the majority element is not guaranteed to exist,
// we need another iteration over the nums to check whether candidate is actually a majority element
int majorityElement(vector<int>& nums) {
    // What candidate equal to in the beginning doesn't matter, it is just an arbitrary guess.
    // candidate will be initialized when the loop starts.
    int candidate = 0;
    int count = 0;

    // You may swap the position of if and else if in this problem if you want,
    // however you cannot do that in 229. Majority Element II, see that question for reasons.
    for (int num : nums) {
        if (num == candidate) {
            ++count;
        } else if (count == 0) {
            // If count == 0, then we've got rid of pairs of different elements, hence we set the new candidate to
            // current num and reset count to 1, all subsequent iterations compare num with current candidate. If they
            // are different, then we get rid of a pair of (candidate, num) and --count, else we get another candidate
            // and ++count.
            candidate = num;
            count = 1;
        } else {
            // In this case, nums != candidate, thus we get rid of one pair of different number
            // (candidate, num)
            --count;
        }
    }

    return candidate;
}

