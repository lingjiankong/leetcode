// Forward declaration of the knows API provided by LeetCode.
bool knows(int a, int b);

int findCelebrity(int n) {

	if (n < 2)
	{
		return -1;
	}

	// Candidate of the celebrity.
	int possible = 0;

	for (int i = 1; i < n; ++i)
	{
		if (knows(possible, i))
		{
			possible = i;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		// If possible knows anyone (except himself), or
		// if there's anyone who doesn't know possible,
		// then there's no celebrity.
		if ((possible != i && (knows(possible, i)) || !knows(i, possible)))
		{
			return -1;
		}
	}

	return possible;
}
