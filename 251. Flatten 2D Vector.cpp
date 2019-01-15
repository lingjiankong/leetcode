// ***
//
// Implement an iterator to flatten a 2d vector.
// 
// Example:
// 
// Input: 2d vector =
// [
//   [1,2],
//   [3],
//   [4,5,6]
// ]
// Output: [1,2,3,4,5,6]
// Explanation: By calling next repeatedly until hasNext returns false,
//              the order of elements returned by next should be: [1,2,3,4,5,6].
//
// ***
//
class Vector2D
{

	public:

		Vector2D(vector<vector<int>>& vec2d)
		{
			x = vec2d.begin(), end = vec2d.end();

			if (x != end)
			{
				y = x->begin();
			}
		}

		int next()
		{
			return *y++;
		}

		bool hasNext()
		{
			// Need while loop here instead of if statement because
			// when you ++x the next vector<int> pointed by *x might be empty.
			// In this case we should keep ++x and looking for a non-empty vector.
			while (x != end && y == x->end())
			{
				++x;
				y = x->begin();
			}

			return x != end;
		}

	private:

		vector<vector<int>>::iterator x, end;

		vector<int>::iterator y;

};
