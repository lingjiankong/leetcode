// `total` records sum(gas)-sum(cost), if this number is non-negative, there must be a solution, which is the "start" returned by our calculation. You will have to remember this math theorem. See Ed's video for intuition. `tank` records what we have left in our gas tank when we *leave* each city, if this number is less than or equal to 0 at city i-1 (meaning we run out of gas as soon as we've left city i-1), there's no way we can travel to the next city i, in this case we just reset start to city i (i.e. by setting tank = gas[i] - cost[i]). There is no need to test the city between old start and city i because we have traveled through them with positive tank (every time when we arrive in a city, we must have non negative gas left in our gas tank; if we test that city again, we will have 0 initial gas, which will not perform any better)

// example input:
// gas  = [1,2,3,4,5]
// cost = [3,4,5,1,2]

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int total = 0;
        int tank = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); ++i) {

            total += gas[i] - cost[i];

            // if tank < 0, meaning we couldn't get city i from city i-1, so we reset tank level to 0, and reset starting point to city i
            if (tank < 0) {
                tank = 0;
                start = i;
            }

            tank += gas[i] - cost[i]; // the amount of gas we have when we leave city[i]
        }

        return total < 0 ? -1 : start;
    }
};
