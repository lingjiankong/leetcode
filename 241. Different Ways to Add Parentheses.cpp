// Recursive solution
// You should be able to understand the solution just by reading the code.
vector<int> diffWaysToCompute(const string& input)
{
	vector<int> output;

	for (int i = 0; i < input.size(); ++i)
	{
		char c = input[i];

		if (ispunct(c))
		{
			// The two for loops below: take the Cartisian product for the left and right part.
			vector<int> leftPart = diffWaysToCompute(input.substr(0, i));
			for (int a : leftPart)
			{
				vector<int> rightPart = diffWaysToCompute(input.substr(i+1));
				for (int b : rightPart)
				{
					output.push_back(c == '+' ? a + b : c == '-' ? a - b : a * b);
				}
			}
		}
	}

	// If output is empty, it means we haven't seen any operator in the string,
	// this indicates that input is just a number, so we return just that input.
	// This is the return condition for the recursion. You may put it in the beginning of the function,
	// but putting it here just looks nicer.
	return output.size() ? output : std::vector<int>({stoi(input)});
}

// Same idea as above, using recursion with memoization
class Solution
{

	public:

		vector<int> diffWaysToCompute(const string& input)
		{
			if (hash.find(input) != hash.end())
			{
				return hash[input];
			}
			
			vector<int> output;

			for (int i = 0; i < input.size(); ++i)
			{
				char c = input[i];

				if (ispunct(c))
				{
					vector<int> leftPart = diffWaysToCompute(input.substr(0, i));
					for (int a : leftPart)
					{
						vector<int> rightPart = diffWaysToCompute(input.substr(i+1));
						for (int b : rightPart)
						{
							output.push_back(c == '+' ? a + b : c == '-' ? a - b : a * b);
						}
					}
				}
			}

			vector<int> result = output.size() ? output : std::vector<int>({stoi(input)});
			hash[input] = result;
			return result;
		}

	private:

		unordered_map<string, vector<int>> hash;

};
