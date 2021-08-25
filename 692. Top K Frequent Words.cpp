// ***
//
// Given an array of strings words and an integer k, return the k most frequent strings.
//
// Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their
// lexicographical order.
//
//
// Example 1:
//
// Input: words = ["i","love","leetcode","i","love","coding"], k = 2
// Output: ["i","love"]
// Explanation: "i" and "love" are the two most frequent words.
// Note that "i" comes before "love" due to a lower alphabetical order.
//
// Example 2:
//
// Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
// Output: ["the","is","sunny","day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4,
// 3, 2 and 1 respectively.
//
//
// Constraints:
//
// 1 <= words.length <= 500
// 1 <= words[i] <= 10
// words[i] consists of lowercase English letters.
// k is in the range [1, The number of unique words[i]]
//
//
// Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
//
// ***

// std::priority_queue and and std::sort using comparator:
//
// vector<int> data = {1,8,5,6,3,4,0,9,7,2};
//
// Given comparator
// auto comp = [](int lhs, int rhs){return lhs < rhs;};
//
// std::priority_queue<int, std::vector<int>, decltype(comp)> pq(comp);
// this comparator is equivalent to using std::less<int>
// largest element has the highest prioirty.
//
// After for(int n : data) pq.push(n),
// Internally, pq is now {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}. Top of the element is ON THE RIGHT
// (i.e. 9. first element to be popped).
// HOWEVER, NOTE THAT if you pop pq and push it to an array, you will get
// {9, 8, 7, 6, 5, 4, 3, 2, 1}
//
// sort(data.begin(), data.end(), comp)
// data is now {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}.

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // Higher frequency has higher priority.
        // If frequency is the same, shorter word and earlier letters have higher priority.
        auto comp = [](const pair<int, string>& lhs, const pair<int, string>& rhs) {
            return lhs.first < rhs.first or (lhs.first == rhs.first and lhs.second > rhs.second);
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);

        unordered_map<string, int> wordToFreq;
        for (string word : words) {
            ++wordToFreq[word];
        }

        for (auto e : wordToFreq) {
            pq.push({e.second, e.first});
            // NOTE: you cannot prematurely pop here if pq.size() > k like other questions.
            // Because of your custom sorting, your decision cannot be made with just k elements.
            // You need to fill the entire pq.
        }

        vector<string> res;
        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
