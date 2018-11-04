// This is kind of a stupid question, nothing too much about certain algorithm.
// Maybe it tests how you use a mix up of for loop and while loop. Still worth look at it.
//
// Explaination about description on the website:
// 4.     1211
// 5.     111221 -> one 1, one 2, two 1s.
string countAndSay(int n)
{
	if (n == 0)
	{
		return "";
	}

	string countAndSay = "1";

	// To calculate the "count and say" of every row.
	// (while(--n) will be executed n-2 times)
	while (--n)
	{
		string current = "";

		// Look at every digit in previous countAndSay,
		// and construct current countAndSay.
		for (int i = 0; i < countAndSay.size(); i++)
		{
			int count = 1;
			while (i < countAndSay.size()-1 && countAndSay[i] == countAndSay[i+1])			
			{
				++count;
				++i;
			}
			current += to_string(count) + countAndSay[i];
		}

		countAndSay = current;
	}

	return countAndSay;
}
