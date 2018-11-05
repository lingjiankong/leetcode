// Brute force solution, worst case O(n^2), works pretty well.
// The idea is that, for every letter in s, treat it as the center of a palindrom.
// The palindrom can be either an odd palindrome live "aba" or an even palindrome like "abba".
// We extend that palindrom and see what length we can get, record the start position and the length.
// There's another DP solution for this problem. Maybe do it in the future.
class Solution
{

	public:

		string longestPalindrome(string s)
		{
			for (int i = 0; i < s.size(); ++i)
			{
				// Asuume the palindrom is odd from current position.
				extendPalindrome(s, i, i);

				// Assume the palindrom is even from current position.
				extendPalindrome(s, i, i+1);
			}

			return s.substr(start, maxLength);
		}

	private:
		
		int start = 0;
		int maxLength = 0;

		void extendPalindrome(const string& s, int i, int j)
		{
			while (i >= 0 && j < s.size() && s[i] == s[j])
			{
				--i, ++j;
			}
			
			// For odd palindrome, the length is at least 1 (the number itself)
			// For even palindrom, the length is at least 0
			if (j - i - 1 > maxLength)
			{
				start = i + 1;
				maxLength = j - i - 1;
			}
		}

};
