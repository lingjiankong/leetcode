// ***
//
// Given an arbitrary ransom note string and another string containing letters from all the magazines,
// write a function that will return true if the ransom note can be constructed from the magazines; otherwise, it will return false.
// 
// Each letter in the magazine string can only be used once in your ransom note.
// 
// Note:
// You may assume that both strings contain only lowercase letters.
// 
// canConstruct("a", "b") -> false
// canConstruct("aa", "ab") -> false
// canConstruct("aa", "aab") -> true
//
// ***
//
// Use same idea (hash set) as 387. First Unique Character in a String.
bool canConstruct(string ransomNote, string magazine)
{
	vector<int> counts(26, 0);

	for (char letter : magazine)
	{
		++counts[letter-'a'];
	}

	for (char letter : ransomNote)
	{
		--counts[letter-'a'];

		if (counts[letter-'a'] < 0)
		{
			return false;	
		}
	}

	return true;
}
