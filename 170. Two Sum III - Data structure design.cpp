// ***
//
// Design and implement a TwoSum class. It should support the following operations: add and find.
// 
// add - Add the number to an internal data structure.
// find - Find if there exists any pair of numbers which sum is equal to the value.
// 
// Example 1:
// 
// add(1); add(3); add(5);
// find(4) -> true
// find(7) -> false
// 
// Example 2:
// 
// add(3); add(1); add(2);
// find(3) -> true
// find(6) -> false
//
// ***
//
// For each numA, we want to see if there is a numB, such that numA + numB = target.
// A special case here to pay attention to is that is numA = numB, then we must check
// if that same element occured more than once (hence we check whether numACount > 1).
// One of the operation in add() and find() must be O(n). You decide the trade-off.
class TwoSum
{

	public:

		void add(int number)
		{
			++hash[number];
		}

		bool find(int target)
		{
			for (auto element : hash)
			{
				int numA = element.first;
				int numACount = element.second;

				int numB = target - numA;

				if ((numB != numA && hash.count(numB)) || (numB == numA && numACount > 1))
				{
					return true;
				}
			}

			return false;
		}

	private:

		unordered_map<int, int> hash;

};
