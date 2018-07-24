// the whole idea is bucket sort

// [ 2,      3,  4, 5,                10, 11,   12,     13     ]
//  (minNum) 3 | 4, 5 |      |      | 10, 11 |  12  |  (maxNum)

// gap = 2, ceil(13-2)/(8-1) = ceil(11/7) = 2
// number of bucket = 7, nums.size()-1 = 8-1 = 7
// 3, 4, 5, 10, 11, 12 are put into the corresponding positon in the bucket

class Solution {
public:
    int maximumGap(vector<int>& nums) {

        if (nums.size() < 2) return 0;

        int n = nums.size();
        int minNum = INT_MAX;
        int maxNum = INT_MIN;

        for (auto num : nums) {
            if (num < minNum) minNum = num;
            if (num > maxNum) maxNum = num;
        }
        if (minNum == maxNum) return 0; // if minNum == maxNum, gap = static_cast<int>(ceil((static_cast<double>(maxNum-minNum)/(n-1)))) will be zero. Later when we select bucket index we will index = (num-minNum)/gap which is devided by zero. We do not want that.

        // gap is the distance between each bucket. The largest gap can not be smaller than (maxNum - minNum) / (n - 1), so if we make the buckets smaller than this number, any gaps within the same bucket is not the amount we are looking for, so we are safe to look only for the inter-bucket gaps.
        // in the extreme case, nums are evenly spaced, for example when we have [3, 5, 7, 9], the largest possible gap in between any two numbers is (9-3)/(4-1) = 6/3 = 2. When we have [1, 1, 2, 1, 1], the largest possible gap in between any two numbers is (2-1)/(5-1) = 1/4, which ceil to 1.
        // actually, if you make the gap between the buckets smaller than the minimum gap required, everything works just fine, so making the buckets smaller doesn't affect the correctness, you might just as well use (maxNum-minNum)/2n, so why do we have std::ceil? Because it avoids the case when gap = 0. We've tested if (minNum == maxNum) above so now maxNum-minNum must be greater than 0, therefore ceil anything greater than 0 will give us 1.

        int gap = static_cast<int>(ceil((static_cast<double>(maxNum-minNum)/(n-1)))); // std::ceil takes floating point values, that's why we cast our integer devision result to double

        vector<int> bucketsMin(n-1, INT_MAX); // the min of each bucket
        vector<int> bucketsMax(n-1, INT_MIN); // the max of each bucket

        for (auto num : nums) {
            if (num == minNum || num == maxNum) continue; // we don't want to put minNum and maxNum in the bucket. We will deal with them in the next loop
            int index = (num-minNum) / gap; // bucket index
            bucketsMin[index] = min(num, bucketsMin[index]);
            bucketsMax[index] = max(num, bucketsMax[index]);
        }

        int maxGap = INT_MIN;

        int prevMax = minNum;
        for (int i = 0; i < n-1; ++i) { // iterate over all buckets (we have n-1 buckets)
            if (bucketsMin[i] == INT_MAX && bucketsMax[i] == INT_MIN) continue; // empty bucket
            maxGap = max(maxGap, bucketsMin[i] - prevMax); // maxGap candidate is the min in current bucket, minus the max in previous bucket (or previous previous previous bucket, if the last two bucket were empty, for example)
            prevMax = bucketsMax[i];
        }
        maxGap = max(maxGap, maxNum - prevMax);

        return maxGap;
    }
};
