// ***
//
// Given a string of numbers and operators, return all possible results from computing all the different possible ways
// to group numbers and operators. The valid operators are +, - and *.
//
// Example 1:
//
// Input: "2-1-1"
// Output: [0, 2]
// Explanation:
// ((2-1)-1) = 0
// (2-(1-1)) = 2
//
// Example 2:
//
// Input: "2*3-4*5"
// Output: [-34, -14, -10, -10, 10]
// Explanation:
// (2*(3-(4*5))) = -34
// ((2*3)-(4*5)) = -14
// ((2*(3-4))*5) = -10
// (2*((3-4)*5)) = -10
// (((2*3)-4)*5) = 10
//
// 1 <= expression.length <= 20
// expression consists of digits and the operator '+', '-', and '*'.
// All the integer values in the input expression are in the range [0, 99].
//
// ***

// Recursive solution
// You should be able to understand the solution just by reading the code.
vector<int> diffWaysToCompute(const string& input) {
    vector<int> result;

    for (int i = 0; i < input.size(); ++i) {
        char symbol = input[i];

        if (ispunct(symbol)) {
            // The two for loops below: take the Cartisian product for the left and right part.
            vector<int> leftPart = diffWaysToCompute(input.substr(0, i));
            vector<int> rightPart = diffWaysToCompute(input.substr(i + 1));
            for (int a : leftPart) {
                for (int b : rightPart) {
                    result.push_back(symbol == '+' ? a + b : symbol == '-' ? a - b : a * b);
                }
            }
        }
    }

    // If result is empty, it means we haven't seen any operator in the string,
    // this indicates that input string itself is just a number, so we return std::vector<int>({stoi(input)}).
    // This is the return condition for the recursion. You may put it in the beginning of the function,
    // but putting it here just looks nicer.
    return result.size() ? result : std::vector<int>({stoi(input)});
}

// Same idea as above, with memoization.
class Solution {
public:
    vector<int> diffWaysToCompute(const string& input) {
        if (_hash.count(input)) {
            return _hash[input];
        }

        vector<int> result;

        for (int i = 0; i < input.size(); ++i) {
            char symbol = input[i];

            if (ispunct(symbol)) {
                vector<int> leftPart = diffWaysToCompute(input.substr(0, i));
                vector<int> rightPart = diffWaysToCompute(input.substr(i + 1));
                for (int a : leftPart) {
                    for (int b : rightPart) {
                        result.push_back(symbol == '+' ? a + b : symbol == '-' ? a - b : a * b);
                    }
                }
            }
        }

        result = result.size() ? result : std::vector<int>({stoi(input)});
        return _hash[input] = result;
    }

private:
    unordered_map<string, vector<int>> _hash;
};

