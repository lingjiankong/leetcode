// ***
//
// Given a non-empty array of integers, return the k most frequent elements.
//
// Example 1:
//
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:
//
// Input: nums = [1], k = 1
// Output: [1]
// Note:
//
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
//
// ***

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> numToFreq;
    priority_queue<pair<int, int>> pq;

    for (int num : nums) {
        ++numToFreq[num];
    }

    for (auto& e : numToFreq) {
        pq.push({e.second, e.first});
    }

    vector<int> topKNums;
    while (k--) {
        int num = pq.top().second;
        pq.pop();
        topKNums.push_back(num);
    }

    return topKNums;
}
