// ***
//
// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words
// beginWord -> s1 -> s2 -> ... -> sk such that:
//
// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences
// from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of
// the words [beginWord, s1, s2, ..., sk].
//
//
// Example 1:
//
// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
// Explanation: There are 2 shortest transformation sequences:
// "hit" -> "hot" -> "dot" -> "dog" -> "cog"
// "hit" -> "hot" -> "lot" -> "log" -> "cog"
//
//
// Example 2:
//
// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: []
// Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
//
//
// Constraints:
//
// 1 <= beginWord.length <= 10
// endWord.length == beginWord.length
// 1 <= wordList.length <= 5000
// wordList[i].length == beginWord.length
// beginWord, endWord, and wordList[i] consist of lowercase English letters.
// beginWord != endWord
// All the words in wordList are unique.
//
// ***

// BFS of paths (instead of words)
// Will TLE on OJ. Just look at the idea.
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> res;
    unordered_set<string> dict(wordList.begin(), wordList.end());
    queue<vector<string>> q;  // Queue of path
    q.push({beginWord});

    int curLevel = 1, minLevel = INT_MAX;
    // All the visited nodes on curLevel. These words will never be visited again after curLevel,
    // and should be removed from wordList. This is guaranteed by BFS.
    unordered_set<string> visited;

    while (!q.empty()) {
        vector<string> curPath = q.front();
        q.pop();

        // Tree pruning.
        if (curPath.size() > curLevel) {
            if (curLevel > minLevel) {
                break;
            }
            for (string w : visited) {
                dict.erase(w);
            }
            visited.clear();
            curLevel = curPath.size();
        }

        // Core BFS on this level.
        string last = curPath.back();
        for (int i = 0; i < last.size(); ++i) {
            string newLast = last;
            for (char c = 'a'; c <= 'z'; ++c) {
                newLast[i] = c;
                if (!dict.count(newLast)) {
                    continue;
                }

                vector<string> nextPath = curPath;
                nextPath.push_back(newLast);
                visited.insert(newLast);

                if (newLast == endWord) {
                    res.push_back(nextPath);
                    minLevel = curLevel;
                } else {
                    q.push(nextPath);
                }
            }
        }
    }

    return res;
}
