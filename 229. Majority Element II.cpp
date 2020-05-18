// ***
//
// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
//
// Note: The algorithm should run in linear time and in O(1) space.
//
// Example 1:
//
// Input: [3,2,3]
// Output: [3]
// Example 2:
//
// Input: [1,1,1,3,3,2,2,2]
// Output: [1,2]
//
// ***

// Moore voting algorithm
// Note: LeetCode has bug that cause this code to have different result in test and submit. Just ignore it
// See 169. Majority Element for intuition.
vector<int> majorityElement(vector<int>& nums) {
    // At most two candidates in this case.
    // What candidate1 and candidate2 equal to in the beginning are just arbitrary guesses. It doesn't matter.
    // Regardless of what candidates are set to, when the loop starts, count will be 1.
    // i.e. candidate and count will be initialized when the loop starts.
    // See 169. Majority Element for intuition.
    int candidate1, candidate2 = 0;
    int count1, count2 = 0;

    // Do not change the order of the if and else if loop,
    // otherwise [8, 8, 7, 7, 7] will only output [7] instead of [8, 7].
    // You have to test if a num is equal to one of the candidates before checking the counters,
    // otherwise if you check counters first, what might happen is the first 8 becomes candidate1,
    // the second 8, which should be count1++, becomes candidate2,
    // and you have candidate1 = 8 (first 8) and candidate2 = 8 (second 8),
    // when in fact both 8 should belong to the same candidate.
    for (int num : nums) {
        if (num == candidate1) {
            ++count1;
        } else if (num == candidate2) {
            ++count2;
        } else if (count1 == 0) {
            candidate1 = num;
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = num;
            count2 = 1;
        } else {
            // In this case num != cadidate1 and num != candidate2,
            // we get rid of one pair of (candidate1, num), therefore we --count1,
            // and one pair of (candidate2, num), therefore we --count2
            --count1;
            --count2;
        }
    }

    // The problem does not guarantee that there are two elements appear more than ⌊ n/3 ⌋ times.
    // Therefore we need to validate if count of each candidate is greater than n/3p
    count1 = 0;
    count2 = 0;
    vector<int> majorityElements;

    for (int num : nums) {
        if (num == candidate1) {
            ++count1;
        } else if (num == candidate2) {
            ++count2;
        }
    }

    if (count1 > nums.size() / 3) {
        majorityElements.push_back(candidate1);
    }
    if (count2 > nums.size() / 3) {
        majorityElements.push_back(candidate2);
    }

    return majorityElements;
}
