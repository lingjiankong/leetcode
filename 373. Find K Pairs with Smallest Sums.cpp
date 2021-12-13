// ***
//
// You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
// Define a pair (u,v) which consists of one element from the first array and one element from the second array.
// Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
//
// Example 1:
//
// Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// Output: [[1,2],[1,4],[1,6]]
// Explanation: The first 3 pairs are returned from the sequence:
//              [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
// Example 2:
//
// Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// Output: [1,1],[1,1]
// Explanation: The first 2 pairs are returned from the sequence:
//              [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
// Example 3:
//
// Input: nums1 = [1,2], nums2 = [3], k = 3
// Output: [1,3],[2,3]
// Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
//
// ***

// Brute force using self-defined sorting rule. Very clear.
vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int, int>> ans;

    for (int i = 0; i < nums1.size(); ++i) {
        for (int j = 0; j < nums2.size(); ++j) {
            ans.push_back({nums1[i], nums2[j]});
        }
    }

    sort(ans.begin(), ans.end(),
         [](pair<int, int>& a, pair<int, int>& b) { return a.first + a.second < b.first + b.second; });

    if (ans.size() > k) {
        ans.erase(ans.begin() + k, ans.end());
    }

    return ans;
}

// Use priority queue so you don't need to sort
vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    auto compare = [](pair<int, int>& a, pair<int, int>& b) { return a.first + a.second < b.first + b.second; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);

    for (int i = 0; i < nums1.size(); ++i) {
        for (int j = 0; j < nums2.size(); ++j) {
            if (pq.size() < k) {
                pq.push({nums1[i], nums2[j]});
            }
            // Check this condition here first so you don't need unnecessary push and pop.
            else if (nums1[i] + nums2[j] < pq.top().first + pq.top().second) {
                pq.push({nums1[i], nums2[j]});
                pq.pop();
            }
        }
    }

    vector<pair<int, int>> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}
