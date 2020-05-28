// ***
//
// Given two arrays, write a function to compute their intersection.
//
// Example 1:
//
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
//
// Example 2:
//
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
//
// ***

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> seen(nums1.begin(), nums1.end());
    unordered_set<int> intersection;

    for (int num : nums2) {
        if (seen.count(num)) {
            intersection.insert(num);
        }
    }

    return vector<int>(intersection.begin(), intersection.end());
}
