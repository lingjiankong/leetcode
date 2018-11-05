// Huahua's video is super clear.
// Maintain two pointers left and right, move them to the center.
// If you see s[l] != s[r], then, to satisfy the problem requirement
// (by deleting either one makes s a palindrom),
// it means either substring s[l+1, r+1) (i.e. by deleting s[l]),
// or s[l, r) (i.e. by deleting s[r]), is a palindrom.
// If neither of those are palindrom, then we do not satisfy the problem requirement.
class Solution
{

	public:

		bool validPalindrome(const string& s)
		{
			int l = 0, r = s.size() - 1;

			while (l < r)
			{
				if (s[l] != s[r])
				{
					return (isPalindrom(s, l+1, r) || isPalindrom(s, l, r-1));
				}
				else
				{
					++l, --r;
				}
			}

			return true;
		}

	private:

		bool isPalindrom(const string& s, int l, int r)
		{
			while (l < r)
			{
				if (s[l++] != s[r--])
				{
					return false;
				}
			}

			return true;
		}
};
