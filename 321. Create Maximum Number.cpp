// Do not watch Ed's video. Huahua's video is very clear http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-321-create-maximum-number/
// The problem logic is clear once you understand it. The problem can be devided into three sub-problems:

// 1. First maxNumber function: Given two arrays nums1 of length n1 and nums2 of length n2 and an integer k, if we want to get k <= n1 + n2 total elements from these two arrays, how many elements should we get from array1 and how many element should we get from array2?
// if we want to have k total number, we can get i numbers from nums1, and get k-i numbers from nums2.
// example:
// nums1 = [4, 2, 8, 5]
// nums2 = [6, 5, 8]
// k = 5
// we can take 3 digits from nums1 and 2 digits from nums2

// 2. Second maxNumber function: How can we choose k elements from an array nums such that the number we get is largest and the order of idividual digit is preserved?
// after the first step, we are able to choose i numbers from nums1 and k-i numbers from nums2. Let's take nums1 for example: we want to know which i elements we should select from nums1 such that the result is "largest" while preserving the order of digits in nums1? We do the same to nums2.
// example:
// nums = [8, 9, 4, 2, 5]
// k = 3
// the "largest" 3-digit number we can choose while preserving the order of digits is [9, 4, 5] (i.e. 945)

// 3. Third maxNumber function: Given two arrays nums1 and nums2, combine them such that the result number is "largest" while preserving the order of digits in each individual array.
// example:
// nums1 = [4, 9, 1]
// nums2 = [7, 2]
// combine them together, the "largest" number while preserving the order of digits in each individual array is [7, 4, 9, 2, 1]

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for (int i = max(0, k-n2); i <= min(n1, k); ++i) { // i = max(0, k-n2) because n2 might be smaller than k, in which case we must select at least k-n2 elements from nums1; i <= min(n1, k) because we do not want i to be out of range of nums1 (in which case we must select the remaining k-n1 elements from nums2), or i being larger than k (in which case we've selected all k elements from num1)
            res = max(res, maxNumber(maxNumber(nums1, i), maxNumber(nums2, k-i)));
        }
        return res;
    }
private:
    vector<int> maxNumber(const vector<int>& nums, int k) {
        vector<int> res; // a stack, if you don't get this part see Huahua's note. The basic idea is to keep our current "largest" in a stack. When we are in the beginning of nums and see a large number (say 9), we may pop everything we've seen before and only saves 9, because you still have so many to add after 9. However if you see 9 until very late in nums, you don't have any "pop quota" to pop elements therefore you may only pop 1 elements and add 9 to the end.
        int popQuota = nums.size() - k; // max number of elements that you are allowed to pop from the stack
        for (auto num : nums) {
            while (!res.empty() && num > res.back() && popQuota-- > 0) {
                res.pop_back(); // when you see a large number, you keep popping back existing elements and move that large number to the beginning of your stack as long as you have the "pop quota". For example you current largest is [3,5,1,6], your pop quota is 7. Now you see a 9, your res will become [9] because your pop quota is 7 so you still have many things to add after 9. However if your pop quota is 1, you might only replace the last element in your stack and your res becomes [3,5,1,9]. If you make your res = [9], you have nothing left to be added after 9.
            }
            res.push_back(num);
        }
        res.resize(k); // we only need the first k elements
        return res;
    }
    // important to use const vector<int>& because you might be passing an rvalue std::vector<int> to the function. A non-const vector<int>& cannot accept rvalue std::vector<int> or literal initialization, and you will get an error: invalid initialization of non-const reference of type 'std::vector<int>&' from an rvalue of type 'std::vector<int>'. As a rule of thumb, if you are calling functions inside functions, you are likely to passing rvalues around, in which case it would be best to use const reference as parameter so it can accept rvalue and literal arguments.
    vector<int> maxNumber(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> res (nums1.size() + nums2.size());
        auto s1 = nums1.begin(), e1 = nums1.end();
        auto s2 = nums2.begin(), e2 = nums2.end();
        int index = 0;
        while(s1 != e1 || s2 != e2) {
            res[index++] = lexicographical_compare(s1, e1, s2, e2) ? *s2++ : *s1++;
        }
        return res;
    }
};
