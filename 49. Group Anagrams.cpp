// ***
//
// Given an array of strings, group anagrams together.
//
// Example:
//
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
//
// Note:
// All inputs will be in lowercase. The order of your output does not matter.
//
// ***

// This solution is clean and good enough.
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // Key: sorted word
    // Value: words whose sorted version are the same
    // Keep in mind that sort takes nlogn, where n is the word lenghth. Might be a bottleneck is a word is super long.
    unordered_map<string, vector<string>> hash;

    for (string word : strs) {
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());
        hash[sortedWord].push_back(word);
    }

    vector<vector<string>> toReturn;

    for (auto element : hash) {
        toReturn.push_back(element.second);
    }

    return toReturn;
}

// Alternatively, we can use the count sort idea similar to 242. Valid Anagram.
// The nlogn cost of sorting each word can be avoided.
vector<vector<string>> groupAnagrams2(vector<string>& strs) {
    unordered_map<string, vector<string>> hash;

    for (string word : strs) {
        vector<int> counts(26, 0);

        for (char letter : word) {
            ++counts[letter - 'a'];
        }

        string anagramIdentifier = "";
        for (int i = 0; i < counts.size(); ++i) {
            anagramIdentifier += '#';
            anagramIdentifier += to_string(counts[i]);
        }

        hash[anagramIdentifier].push_back(word);
    }

    vector<vector<string>> toReturn;

    for (auto element : hash) {
        toReturn.push_back(element.second);
    }

    return toReturn;
}
