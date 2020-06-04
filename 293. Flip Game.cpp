// ***
//
// You are playing the following Flip Game with your friend:
// Given a string that contains only these two characters: + and -, you and your friend take turns to flip two
// consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will
// be the winner.
//
// Write a function to compute all possible states of the string after one valid move.
//
// Example:
//
// Input: s = "++++"
// Output:
// [
//   "--++",
//   "+--+",
//   "++--"
// ]
//
// Note: If there is no valid move, return an empty list [].
//
// ***
//
// Simply traverse the string, if you see two consecutive ++,
// Turn them into -- and push_back the resulting string,
// then you revert those -- to the original ++ and continue the iteration.
//
// In these kind of question, I prefer for (int i = 1; i < s.size(); ++i)
// rather than for (int i = 0; i < s.size()-1; ++i),
// because container.size() is always an unsigned int,
// if the container size is 0, then 0-1 overflows.

vector<string> generatePossibleNextMoves(string s) {
    vector<string> result;

    for (int i = 1; i < s.size(); ++i) {
        if (s[i - 1] == '+' && s[i] == '+') {
            s[i - 1] = s[i] = '-';
            result.push_back(s);
            s[i - 1] = s[i] = '+';
        }
    }

    return result;
}
