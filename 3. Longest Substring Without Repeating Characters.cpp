// The basic idea is, keep a hashmap which stores the characters in string as keys and their positions as values,
// and keep two pointers which define the max substring (the left pointer is `start` and the right pointer is `i`).
// Move the right pointer (i) to scan through the string, and meanwhile update the hashmap.
// 1. If the character is already in the hashmap, meaning we've seen a duplicated character,
// 2. AND, if current left pointer (start) is to the left of that duplicate letter,
//
// Why do we need to check if start <= seen[s[i]]?
// 
// Suppose you have whateverZwhateverwhateverwhateverZ... Z occurs somewhere near the beginning.
// If you do not check for 
// 
//
// then move the left pointer (start) to the right of the same character last found.
// Note that the two pointers can only move forward.
//
// Example:
// xyzabcdefghijklmna...
//     ^            ^
//     start        i
//
// Therefore the length is i - start + 1
int lengthOfLongestSubstring(string s)
{
	unordered_map<char, int> seen;

	int maxLength = 0;
	int start = 0;

	for (int i = 0; i < s.size(); ++i)
	{
		if (seen.find(s[i]) != seen.end() && start <= seen[s[i]])
		{
			start = seen[s[i]] + 1;
		}

		maxLength = max(maxLength, i - start + 1);
		seen[s[i]] = i;
	}

	return maxLength;
}

// Idea is the same, just another way of thinking:
// This time, start is the index of last occurance of s[i] 
//
// Example:
// _abcdefghijklmn...
// ^             ^
// start = -1    i
//
// xyzabcdefghijklmna...
//    ^             ^
//    start         i
//
// Therefore the length is i - start
int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> seen;

    int maxLength = 0;
    int start = -1;

    for (int i = 0; i < s.size(); ++i)
    {
        if (seen.find(s[i]) != seen.end() && start < seen[s[i]])
        {
            start = seen[s[i]];
        }

        maxLength = max(maxLength, i - start);
        seen[s[i]] = i;
    }

    return maxLength;
}
