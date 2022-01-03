// ***
//
// You are given an integer array of unique positive integers nums. Consider the following graph:
//
// There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
// There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
// Return the size of the largest connected component in the graph.
//
//
// Example 1:
//
// Input: nums = [4,6,15,35]
// Output: 4
//
//
// Example 2:
//
// Input: nums = [20,50,9,63]
// Output: 2
//
//
// Example 3:
//
// Input: nums = [2,3,6,7,4,12,21,39]
// Output: 8
//
//
// Constraints:
//
// 1 <= nums.length <= 2 * 104
// 1 <= nums[i] <= 105
// All the values of nums are unique.
//
// ***

// TLE but the idea is correct.
// Because this problem has large data size, we cannot just simply calculate whether a node and every other node share a
// common factor (O(n2) will for sure TLE). Instead, the idea is to construct a graph from 1 to max(nums) (i.e. all
// numbers in nums + all possible factors). When traversing every number, we connect it with all of its factors. In the
// end, we can manually calculate which numbers share the same root and return the maximum cluster.
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());
        UnionFind<int> uf;
        for (int num = 1; num <= maxElement; ++num) {
            uf.add(num);
        }

        for (int num : nums) {
            for (int k = 2; k <= sqrt(num); ++k) {
                if (num % k == 0) {
                    // num = k * num / k, connect the num's two factors, k and num / k
                    uf.connect(num, k);
                    uf.connect(num, num / k);
                }
            }
        }

        // Cannot call uf.size() directly since uf includes elements which are not part of nums.
        map<int, int> clusterSizes;
        int maxSize = 1;
        for (int num : nums) {
            int root = uf.findRoot(num);
            maxSize = max(maxSize, ++clusterSizes[root]);
        }

        return maxSize;
    }
};
