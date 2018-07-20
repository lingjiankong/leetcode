// Edward's solution video was not very clear
// below is the most intuitive solution, based on the same idea as his, but using cleaner code

class Solution {
public:
    string getHint(string secret, string guess) {

        if (secret.empty()) // secret and guess always equal, as in the problem description
            return "0A0B";

        vector<int> secretCount (10, 0); // count how many times a particular digit appear in secret (exculding digits that match in the first place)
        vector<int> guessCount (10, 0); // count how many times a particular digit appear in guess (exculding digits that match in the first place)

        int numBull = 0;
        int numCow = 0;

        for (int i = 0; i < secret.size(); ++i) {

            if (secret[i] == guess[i]) {
                ++numBull;
            }
            else {
                ++secretCount[secret[i]-'0'];
                ++guessCount[guess[i]-'0'];
            }
        }

        for (int i = 0; i < secretCount.size(); ++i) {
            numCow += min(secretCount[i], guessCount[i]);
        }

        return to_string(numBull) + 'A' + to_string(numCow) + 'B';
    }
};
