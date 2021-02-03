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

// 1. Find the sorted nth element
// std::nth_element(RandomIt first, RandomIt nth, RandomIt last)
// std::nth_element(): rearranges the elements in the range [first,last),
// in such way that the element at the nth position is the element that would be
// in that position in a sorted sequence. The other elements are left without any specific order,
// except that none of the elements preceding nth are greater than it, and none of the elements following it are less.
int majorityElement(vector<int>& nums) {
    nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
    return nums[nums.size() / 2];
}

// 2a. Moore voting alogorithm.
// This is exactly the same as 2b. below, just make the algorithm clear so you know what's going on.
//
// Basic idea of the algorithm is if we cancel out each occurrence of an element e with
// all the other elements that are different from e, then e will exist utill the end if it is the majority element.
// Code below loops through each element and maintains a count of the element that has the potential of
// being the majority element. If next element is same then increments the count, otherwise decrements the count.
// If the count reaches 0 then update the potential index to the current element and sets count to 1.
int majorityElement(vector<int>& nums) {
    int majorityElementCandidateIndex = 0;
    int count = 1;

    for (int i = 1; i < nums.size(); ++i) {
        nums[majorityElementCandidateIndex] == nums[i] ? ++count : --count;

        if (count == 0) {
            majorityElementCandidateIndex = i;
            count = 1;
        }
    }

    return nums[majorityElementCandidateIndex];
}

// 2b. Moore voting algorithm.
// This is a more generic form, see 229. Majority Element II.
//
// The idea is to repeatedly get rid of pairs of different element,
// after which the element left must be the majority element.
// Note that, in the problem statement, a majority element is guaranteed to exist.
// If the majority element is not guaranteed to exist,
// we need another iteration over the nums to check whether majorityElementCandidate is actually a majority element
int majorityElement(vector<int>& nums) {
    // What majorityElementCandidate equal to in the beginning doesn't matter, it is just an arbitrary guess.
    // majorityElementCandidate will be initialized when the loop starts.
    int majorityElementCandidate = 0;
    int count = 0;

    // You may swap the position of if and else if in this problem if you want,
    // however you cannot do that in 229. Majority Element II, see that question for reasons.
    for (int num : nums) {
        if (num == majorityElementCandidate) {
            ++count;
        } else if (count == 0) {
            // If count == 0, then we've got rid of pairs of different elements,
            // Hence we set the new majorityElementCandidate to current num, all subsequent iterations compare num with
            // current majorityElementCandidate. If they are different, then we get rid of a pair of
            // (majorityElementCandidate, num) and --count, else we get another majorityElementCandidate and ++count.
            majorityElementCandidate = num;
            count = 1;
        } else {
            // In this case, nums != majorityElementCandidate, thus we get rid of one pair of different number
            // (majorityElementCandidate, num)
            --count;
        }
    }

    return majorityElementCandidate;
}

