// Edward's solution video was not very clear
// Below is the most intuitive solution,
// based on the same idea as his, but using cleaner code.
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

	for (int i = 0; i < secret.size(); ++i) {

		if (secret[i] == guess[i])
		{
			++numBull;
		}
		else
		{
			// -'0' converts str to int so we can use it as index
			++secretCount[secret[i]-'0'];
			++guessCount[guess[i]-'0'];
		}
	}

	for (int i = 0; i < secretCount.size(); ++i) {
		numCow += min(secretCount[i], guessCount[i]);
	}

	return to_string(numBull) + 'A' + to_string(numCow) + 'B';
}
