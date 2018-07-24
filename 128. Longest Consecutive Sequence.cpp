class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> seen(nums.begin(), nums.end());
        int res = 0;

        for (int num : nums) {
            int up = num + 1;
            while (seen.find(up) != seen.end()) {
                seen.erase(up);
                ++up;
            }

            int down = num - 1;
            while (seen.find(down) != seen.end()) {
                seen.erase(down);
                --down;
            }

            res = max(res, up-down-1);
        }

        return res;
    }
};
