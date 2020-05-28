// ***
//
// Given two arrays, write a function to compute their intersection.
//
// Example 1:
//
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
// Example 2:
//
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Note:
//
// Each element in the result should appear as many times as it shows in both arrays.
// The result can be in any order.
//
// ***

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> seenCount;
    vector<int> intersection;

    for (int num : nums1) {
        ++seenCount[num];
    }

    for (int num : nums2) {
        if (seenCount[num]-- > 0) {
            intersection.push_back(num);
        }
    }

    return intersection;
}
