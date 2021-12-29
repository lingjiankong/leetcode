// ***
//
// Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no
// palindromic permutation could be form.
//
// Example 1:
//
// Input: "aabb"
// Output: ["abba", "baab"]
// Example 2:
//
// Input: "abc"
// Output: []
//
// ***
//
// The idea is very simple. Read the comments.
// To be able to form palindromic permutations (of the same size as s) from string s, we must make sure that at most one
// letter occurs odd number of times. If more than one letter occurs odd number of times, then we are unable to form
// any palindromic permutations, in this case just return empty vector.

// Using next_permutation()
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> all;
        unordered_map<char, int> letterCount;

        // i.e. Our results will be frontHalf + middleLetter + reverse(frontHalf)
        // for all possible permutations of frontHalf.
        string frontHalf, middleLetter;

        for (char letter : s) {
            ++letterCount[letter];
        }

        for (auto &e : letterCount) {
            // If we see a letter occur odd number of times, that letter must be the middle letter.
            if (e.second % 2 == 1) {
                middleLetter += e.first;
            }

            // Depending on how many times the letter appears, we will add the letter to frontHalf.
            // Note we have e.second / 2 here because when we add the letter to frontHalf,
            // the letter implicitly will appear in the backHalf. For example, if we see letter "a" 6 times,
            // then frontHalf += "aaa".
            frontHalf += string(e.second / 2, e.first);

            // If more than one letter occurs odd number of times,
            // then we are unable to form any palindromic permutations.
            if (middleLetter.size() > 1) {
                return {};
            }
        }

        // Need to sort before calling next_permutation().
        sort(frontHalf.begin(), frontHalf.end());

        do {
            all.push_back(frontHalf + middleLetter + string(frontHalf.rbegin(), frontHalf.rend()));
        } while (next_permutation(frontHalf.begin(), frontHalf.end()));

        return all;
    }
};

// Write permutation function ourselves (vanilla permutation function, see 47. Permutations II).
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> letterCount;

        string frontHalf, middleLetter;

        for (auto letter : s) {
            ++letterCount[letter];
        }

        for (auto &element : letterCount) {
            if (element.second % 2 == 1) {
                middleLetter += element.first;
            }

            frontHalf += string(element.second / 2, element.first);

            if (middleLetter.size() > 1) {
                return {};
            }
        }

        vector<string> all;
        sort(frontHalf.begin(), frontHalf.end());
        vector<bool> visited(frontHalf.size());
        string current;

        _permute(frontHalf, current, all, visited, middleLetter);

        return all;
    }

private:
    void _permute(string &s, string &current, vector<string> &all, vector<bool> &visited, string &middleLetter) {
        if (current.size() == s.size()) {
            all.push_back(current + middleLetter + string(current.rbegin(), current.rend()));
            return;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (visited[i]) {
                continue;
            }

            if (i > 0 and s[i] == s[i - 1] and visited[i - 1]) {
                continue;
            }

            visited[i] = true;
            current.push_back(s[i]);
            _permute(s, current, all, visited, middleLetter);
            current.pop_back();
            visited[i] = false;
        }
    }
};

// Same idea. Write permutation function ourselves (taking advantage of letterCount).
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> letterCount;

        string frontHalf, middleLetter;

        for (auto letter : s) {
            ++letterCount[letter];
        }

        // Element needs to be a referece here, see comments.
        for (auto &e : letterCount) {
            if (e.second % 2 == 1) {
                middleLetter += e.first;
            }

            // e.second /= 2 in place is needed because we want to alter it in the the original letterCount.
            // Hash map letterCount with count for only the front half of the palindrome is needed for
            // backtracking later (letterCount serves as "visited").
            e.second /= 2;
            frontHalf += string(e.second, e.first);

            if (middleLetter.size() > 1) {
                return {};
            }
        }

        vector<string> all;
        string current;
        _permute(frontHalf, letterCount, middleLetter, current, all);

        return all;
    }

private:
    void _permute(string &frontHalf, unordered_map<char, int> &letterCount, string middleLetter, string current,
                  vector<string> &all) {
        if (current.size() == frontHalf.size()) {
            all.push_back(current + middleLetter + string(current.rbegin(), current.rend()));
            return;
        }

        for (auto &e : letterCount) {
            if (e.second > 0) {
                --e.second;
                _permute(frontHalf, letterCount, middleLetter, current + e.first, all);
                ++e.second;
            }
        }
    }
};

