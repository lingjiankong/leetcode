class WordDistance {
public:
    WordDistance(vector<string> words) {
        for(int i = 0; i < words.size(); ++i) {
            wordMap[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int i = 0, j = 0, minDis = INT_MAX;
        while (i < wordMap[word1].size() && j < wordMap[word2].size()) {
            minDis = min(minDis, abs(wordMap[word1][i]-wordMap[word2][j]));
            wordMap[word1][i] < wordMap[word2][j] ? ++i : ++j; // the trick is here!
        }
        return minDis;
    }
private:
    unordered_map<string, vector<int>> wordMap;
};


/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
