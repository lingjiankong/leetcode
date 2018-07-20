// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {

        if (n < 2)
            return -1;

        int possible = 0;
        for (int i = 1; i < n; ++i) {
            if (knows(possible, i))
                possible = i;
        }

        for (int i = 0; i < n; ++i) {
            if (possible != i && (knows(possible, i) || !knows(i, possible)))
                return -1;
        }

        return possible;
    }
};
