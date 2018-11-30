// ***
//
// You are playing the following Bulls and Cows game with your friend:
// You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess,
// you provide a hint that indicates how many digits in said guess match your secret number exactly
// in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows").
// Your friend will use successive guesses and hints to eventually derive the secret number.
// 
// Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 
// Please note that both secret number and friend's guess may contain duplicate digits.
// 
// Example 1:
// Input: secret = "1807", guess = "7810"
// Output: "1A3B"
// 
// Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
//
// Example 2:
// Input: secret = "1123", guess = "0111"
// Output: "1A1B"
// 
// Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
// Note: You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
//
// ***
//
// Bulls are easy to calculate, simply check if secret[i] == guess[i].
//
// For cows, calculate how many a digit appears in secret and
// how many times a digit appears in guess (excluding digits that match in the first place i.e. bulls),
// and take the minimum. This is the number of cows for that particular digit.
//
// For example, if number 4 appears 3 times in secret and 5 times in guess (but neither is bull),
// secret: 4 4 4 5 6 7 8 9 9 9
// guess:  1 2 3 4 5 4 4 4 4 5 
// then the number of cows for number 4 is just 3.
//
string getHint(string secret, string guess)
{
	// Secret and guess always equal, as in the problem description
	if (secret.empty())
	{
		return "0A0B";
	}

	// Count how many times a particular digit appear in secret
	// (exculding digits that match in the first place i.e. bulls)
	vector<int> secretCount (10, 0);

	// Count how many times a particular digit appear in guess
	// (exculding digits that match in the first place i.e. bulls)
	vector<int> guessCount (10, 0);

	int numBull = 0;
	int numCow = 0;

	for (int i = 0; i < secret.size(); ++i)
	{
		if (secret[i] == guess[i])
		{
			++numBull;
		}
		else
		{
			++secretCount[secret[i]-'0'];
			++guessCount[guess[i]-'0'];
		}
	}

	for (int i = 0; i < secretCount.size(); ++i)
	{
		numCow += min(secretCount[i], guessCount[i]);
	}

	return to_string(numBull) + 'A' + to_string(numCow) + 'B';
}
