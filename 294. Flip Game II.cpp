// Very clear explanation: https://www.youtube.com/watch?v=oL2J_N1CLzI
// See also 293. Flip Game.
//
// The idea is that if you are guaranteed to win by choosing certain move,
// then in that case the opponent is guaranteed to not win the game.
// Therefore, if the opponent is guaranteed not to win the game, then we known we must win the game.
// 1. Recursive only solution:
//
bool canWin(string& s)
{
	for (int i = 1; i < s.size(); ++i)	
	{
		if(s[i-1] == '+' && s[i] == '+')
		{
			s[i-1] = s[i] = '-';
			bool opponentWin = canWin(s);
			s[i-1] = s[i] = '+';

			if (!opponentWin)
			{
				return true;
			}
		}
	}

	return false;
}

// 2. Recursion + memoization
bool canWin(string& s)
{
	unordered_map<string, bool> hash;
	return dfs(s, hash);
}

bool dfs(string& s, unordered_map<string, bool>& hash)
{
	if(hash.find(s) != hash.end())
	{
		return hash[s];
	}

	for (int i = 1; i < s.size(); ++i)	
	{

		if(s[i-1] == '+' && s[i] == '+')
		{
			s[i-1] = s[i] = '-';
			bool opponentWin = dfs(s, hash);
			s[i-1] = s[i] = '+';

			hash[s] = !opponentWin;
			if (!opponentWin)
			{
				return true;
			}
		}
	}

	hash[s] = false;
	return false;
}
