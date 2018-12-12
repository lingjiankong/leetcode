// ***
//
// You are playing the following Flip Game with your friend:
// Given a string that contains only these two characters: + and -,
// you and your friend take turns to flip two consecutive "++" into "--".
// The game ends when a person can no longer make a move and therefore the other person will be the winner.
// 
// Write a function to determine if the starting player can guarantee a win.
// 
// Example:
// 
// Input: s = "++++"
// Output: true 
// Explanation: The starting player can guarantee a win by flipping the middle "++" to become "+--+".
//
// ***
//
// Very clear explanation: https://www.youtube.com/watch?v=oL2J_N1CLzI
// See also 293. Flip Game.
//
// This is a backtracking problem.
// The idea is that if you are guaranteed to win by choosing certain move,
// then in that case the opponent is guaranteed to not win the game.
// Therefore, if the opponent is guaranteed not to win the game, then we known we must win the game.
//
// 1. Recursive only solution:
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

// 2. Recursion + memoization:
bool canWin(string& s)
{
	unordered_map<string, bool> hash;
	return backtrack(s, hash);
}

bool backtrack(string& s, unordered_map<string, bool>& hash)
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
			bool opponentWin = backtrack(s, hash);
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
