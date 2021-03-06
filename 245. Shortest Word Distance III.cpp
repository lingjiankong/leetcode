// ***
//
// Given a list of words and two words word1 and word2, return the shortest distance between these two words in the
// list.
//
// word1 and word2 may be the same and they represent two individual words in the list.
//
// Example:
//
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//
// Input: word1 = “makes”, word2 = “coding”
// Output: 1
//
// Input: word1 = "makes", word2 = "makes"
// Output: 3
//
// Note:
// You may assume word1 and word2 are both in the list.
//
// ***
//
// See also 243. Shortest Word Distance I.

int shortestWordDistance(vector<string>& words, string word1, string word2) {
    int pos1 = -1, pos2 = -1;
    int minDis = INT_MAX;

    for (int i = 0; i < words.size(); ++i) {
        if (words[i] == word1) {
            pos1 = i;
        }
        if (words[i] == word2) {
            // If word1 and word2 are the same, we assign current index i to pos2, and pos1 becomes last pos2 (last pos2
            // is the last time we've seen the same word) (if we don't do it, and word1 is the same as word2, then pos1
            // and pos2 will be the same everytime that same word is encountered, which will give minDis = 0).
            if (word1 == word2) {
                pos1 = pos2;
            }

            pos2 = i;
        }

        if (pos1 != -1 && pos2 != -1) {
            minDis = min(minDis, abs(pos2 - pos1));
        }
    }

    return minDis;
}
