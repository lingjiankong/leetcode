// ***
//
// Design a class which receives a list of words in the constructor, and implements a method that takes two words word1
// and word2 and return the shortest distance between these two words in the list. Your method will be called repeatedly
// many times with different parameters.
//
// Example:
//
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//
// Input: word1 = “coding”, word2 = “practice”
// Output: 3
//
// Input: word1 = "makes", word2 = "coding"
// Output: 1
//
// Note:
// You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
//
// Your WordDistance object will be instantiated and called as such:
// WordDistance obj = new WordDistance(words);
// int param_1 = obj.shortest(word1,word2);
//
// ***

// Straight forward solution, O(mn)
class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            _wordToIndexes[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int res = INT_MAX;
        for (int i = 0; i < _wordToIndexes[word1].size(); ++i) {
            for (int j = 0; j < _wordToIndexes[word2].size(); ++j) {
                res = min(res, abs(_wordToIndexes[word1][i] - _wordToIndexes[word2][j]));
            }
        }
        return res;
    }

private:
    unordered_map<string, vector<int>> _wordToIndexes;
};

// Optimized solution, O(m+n)
class WordDistance {
public:
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); ++i) {
            _wordToIndexes[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int i = 0, j = 0;
        int minDis = INT_MAX;

        while (i < _wordToIndexes[word1].size() && j < _wordToIndexes[word2].size()) {
            minDis = min(minDis, abs(_wordToIndexes[word1][i] - _wordToIndexes[word2][j]));

            // The trick is here.
            // We know that in _wordToIndexes, each word's indexes in words are in ascending order. We want to comapre
            // the current indexes pointed to by i and j, and increase the pointer which points to the smaller index, in
            // order to get two indexes as close as possible and hopefully get a smaller minDis.
            _wordToIndexes[word1][i] < _wordToIndexes[word2][j] ? ++i : ++j;
        }

        return minDis;
    }

private:
    unordered_map<string, vector<int>> _wordToIndexes;
};
