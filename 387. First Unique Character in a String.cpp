// ***
//
// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
//
// Examples:
//
// s = "leetcode"
// return 0.
//
// s = "loveleetcode",
// return 2.
//
// ***

// Method 1: Traverse the string twice.
int firstUniqChar(string s) {
    // Stores how many times a particular letter has been seen.
    vector<int> counts(26, 0);

    for (int i = 0; i < s.size(); ++i) {
        ++counts[s[i] - 'a'];
    }

    for (int i = 0; i < s.size(); ++i) {
        if (counts[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}

// Method 2: Frist traverse the string, then traverse 26 letters.
// This could be faster if string is long because you only need to traverse the string once.
int firstUniqChar(string s) {
    // .first stores how many times that particular letter has been seen.
    // .second stores the last time that letter has been seen.
    //
    // If a letter is non-repeating, then .first must be 1,
    // and .second is just first time (which is also the last time) it has been seen.
    // If multiple non-repeating letters exist, we take the one which we saw the earliest.
    //
    // Note that in pair<int, int>, both ints are zero-initialized.
    // You may as well do vector<pair<int, int>> counts(26, {0, 0}) to be more explicit.
    vector<pair<int, int>> counts(26);

    for (int i = 0; i < s.size(); ++i) {
        ++counts[s[i] - 'a'].first;
        counts[s[i] - 'a'].second = i;
    }

    int index = INT_MAX;
    for (int i = 0; i < counts.size(); ++i) {
        if (counts[i].first == 1) {
            index = min(index, counts[i].second);
        }
    }

    return index == INT_MAX ? -1 : index;
}
