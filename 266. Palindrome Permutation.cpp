// Just check that no more than one character appears an odd number of times.
// Because if there is one, then it must be in the middle of the palindrome.
// So we can't have two of them.
bool canPermutePalindrome(const string& s)
{
	bitset<256> seen;

	for (char letter : s)
	{
		seen.flip(letter);
	}

	return seen.count() <= 1;
}
