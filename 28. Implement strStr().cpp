// ***
//
// Implement strStr().
// 
// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
// 
// Example 1:
// Input: haystack = "hello", needle = "ll"
// Output: 2
//
// Example 2:
// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
//
// Clarification:
// What should we return when needle is an empty string? This is a great question to ask during an interview.
// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
//
// ***
//
// Just brute force solution. Read the code.
int strStr(string haystack, string needle)
{
	if (needle.size() == 0)
	{
		return 0;
	}

	for (int i = 0; i < haystack.size(); ++i)
	{

		// If this is the case then it is not possible for the remaining haystack to contain needle
		if (i + needle.size() > haystack.size())
		{
			break;
		}

		for (int j = 0; j < needle.size(); ++j)
		{
			if (haystack[i+j] != needle[j])
			{
				break;
			}

			if (j == needle.size()-1)
			{
				return i;
			}
		}
	}

	return -1;
}
