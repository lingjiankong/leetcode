// Moore voting algorithm
// note: LeetCode has bug that cause this code to have different result in test and submit. Just ignore it

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        // at most two candidates in this case
        int candidate1, candidate2 = 0;
        int count1, count2 = 0;

        // do not change the order of the if elif loop, otherwise [8, 8, 7, 7, 7] will only output [7] instead of [8, 7]. You have to test if a num is equal to one of the candidates before checking the counters, otherwise if you check counters first, what might happen is the first 8 becomes candidate1, the second 8, which should be count1++, becomes candidate2, and you have candidate1 = 8 (first 8) and candidate2 = 8 (second 8), when in fact both 8 shoul belong to the same candidate.
        for (auto num : nums) {
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
                // i.e. num != cadidate1 and num != candidate2, we get rid of one pair of (candidate1, num), --count1, and one pair of (candidate2, num), --count2
                --count1;
                --count2;
            }
        }

        // validate if count of each candidate is greater than n/3
        count1 = 0;
        count2 = 0;
        vector<int> res {};
        for (auto num : nums) {
            if (num == candidate1) ++count1;
            else if (num == candidate2) ++count2;
        }
        if (count1 > nums.size()/3) res.push_back(candidate1);
        if (count2 > nums.size()/3) res.push_back(candidate2);

        return res;
    }
};
