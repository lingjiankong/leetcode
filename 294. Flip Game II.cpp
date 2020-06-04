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
// See also 293. Flip Game.
//
// This is a recursion problem. It is a good thinking process to understand recursion.
// The idea is that if you are guaranteed to WIN by choosing certain move,
// then in that case the opponent is guaranteed to NOT WIN the game.
// Therefore, if we figured out that the opponent is guaranteed not to win the game, then we know we must win the game.

// 1. Recursive only solution:
bool canWin(string& s) {
    for (int i = 1; i < s.size(); ++i) {
        if (s[i - 1] == '+' && s[i] == '+') {
            s[i - 1] = s[i] = '-';
            bool opponentWin = canWin(s);
            s[i - 1] = s[i] = '+';

            if (!opponentWin) {
                return true;
            }
        }
    }

    // false will be returned if we have never entered the if statement above (the case when no consecutive +'s
    // availabe so we have no more moves). Even if we were inside if statement, if opponent always wins, we will
    // eventually return false as well.
    return false;
}

// 2. Recursion + memoization:
bool canWin(string& s) {
    // hash[s] tracks whether we can win (i.e. !opponentWin) given string s.
    unordered_map<string, bool> hash;
    return backtrack(s, hash);
}

bool backtrack(string& s, unordered_map<string, bool>& hash) {
    if (hash.count(s)) {
        return hash[s];
    }

    for (int i = 1; i < s.size(); ++i) {
        if (s[i - 1] == '+' && s[i] == '+') {
            s[i - 1] = s[i] = '-';
            bool opponentWin = backtrack(s, hash);
            s[i - 1] = s[i] = '+';

            hash[s] = !opponentWin;
            if (!opponentWin) {
                return true;
            }
        }
    }

    hash[s] = false;
    return false;
}
