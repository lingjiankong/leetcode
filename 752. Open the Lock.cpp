// ***
//
// You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6',
// '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'.
// Each move consists of turning one wheel one slot.
//
// The lock initially starts at '0000', a string representing the state of the 4 wheels.
//
// You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock
// will stop turning and you will be unable to open it.
//
// Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of
// turns required to open the lock, or -1 if it is impossible.
//
//
// Example 1:
//
// Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
// Output: 6
// Explanation:
// A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
// Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
// because the wheels of the lock become stuck after the display becomes the dead end "0102".
//
// Example 2:
//
// Input: deadends = ["8888"], target = "0009"
// Output: 1
// Explanation:
// We can turn the last wheel in reverse to move from "0000" -> "0009".
//
// Example 3:
//
// Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
// Output: -1
// Explanation:
// We can't reach the target without getting stuck.
//
// Example 4:
//
// Input: deadends = ["0000"], target = "8888"
// Output: -1
//
//
// Constraints:
//
// 1 <= deadends.length <= 500
// deadends[i].length == 4
// target.length == 4
// target will not be in the list deadends.
// target and deadends[i] consist of digits only.
//
// ***

// BFS
// You may also add deadends to visited and check only visited.
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> notAllowed(deadends.begin(), deadends.end());

        queue<string> q;
        q.push("0000");

        unordered_set<string> visited;
        visited.insert("0000");

        int numTurns = 0;
        while (not q.empty()) {
            int qSize = q.size();
            while (qSize--) {
                string curCode = q.front();
                q.pop();

                // Check it here in case "0000" itself is not allowed.
                // Typically, you check this while you are checking visited.
                if (notAllowed.count(curCode)) {
                    continue;
                }

                if (curCode == target) {
                    return numTurns;
                }

                for (int i = 0; i < 4; ++i) {
                    string up = plusOne(curCode, i);
                    if (not visited.count(up)) {
                        q.push(up);
                        visited.insert(up);  // Note where we insert element to visited. Compare to bidirectional BFS.
                    }

                    string down = minusOne(curCode, i);
                    if (not visited.count(down)) {
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            ++numTurns;
        }

        return -1;
    }

private:
    string plusOne(const string& code, int i) {
        string res = code;
        if (code[i] == '9') {
            res[i] = '0';
        } else {
            res[i] = ((code[i] - '0') + 1) + '0';
        }
        return res;
    }

    string minusOne(const string& code, int i) {
        string res = code;
        if (code[i] == '0') {
            res[i] = '9';
        } else {
            res[i] = ((code[i] - '0') - 1) + '0';
        }
        return res;
    }
};

// Bidirectional BFS
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited;
        unordered_set<string> notAllowed(deadends.begin(), deadends.end());

        int numTurns = 0;

        unordered_set<string> q1;
        q1.insert("0000");

        unordered_set<string> q2;
        q2.insert(target);

        while (not q1.empty() and not q2.empty()) {
            // Always expand q1 (the smaller set).
            if (q1.size() > q2.size()) {
                swap(q1, q2);
            }

            unordered_set<string> temp;  // to be assigned later to q1.
            for (string& s : q1) {
                // Unidirectional BFS: add to visited when adding to queue.
                // Bidirectional BFS: add to visited when popping from queue.
                visited.insert(s);

                if (notAllowed.count(s)) {
                    continue;
                }

                if (q2.count(s)) {
                    return numTurns;
                }

                for (int i = 0; i < 4; ++i) {
                    string up = plusOne(s, i);
                    if (not visited.count(up)) {
                        temp.insert(up);
                    }

                    string down = minusOne(s, i);
                    if (not visited.count(down)) {
                        temp.insert(down);
                    }
                }
            }
            ++numTurns;
            q1 = temp;
        }

        return -1;
    }

private:
    string plusOne(const string& code, int i) {
        string res = code;
        if (code[i] == '9') {
            res[i] = '0';
        } else {
            res[i] = ((code[i] - '0') + 1) + '0';
        }
        return res;
    }

    string minusOne(const string& code, int i) {
        string res = code;
        if (code[i] == '0') {
            res[i] = '9';
        } else {
            res[i] = ((code[i] - '0') - 1) + '0';
        }
        return res;
    }
};
