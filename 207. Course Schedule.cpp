// ***
//
// There are a total of n courses you have to take, labeled from 0 to n-1.
// 
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
// 
// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
// 
// Example 1:
// 
// Input: 2, [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
//              To take course 1 you should have finished course 0. So it is possible.
// Example 2:
// 
// Input: 2, [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
//              To take course 1 you should have finished course 0, and to take course 0 you should
//              also have finished course 1. So it is impossible.
//
// ***
//
// This question is the same as asking us to detect whether there's loop in a graph.
//
class Solution
{

	public:

		bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
		{
			// Construct the graph
			mGraph = vector<vector<int>>(numCourses);
			for(auto course : prerequisites)
			{
				mGraph[course.second].push_back(course.first);
			}
			
			// Initialize the initial visitingStatus for all courses to be unknown.
			vector<State> visitingStatus(numCourses, State::Unknown);
			for(int i = 0; i < numCourses; ++i)
			{
				// If backtrack returns true then there's a cycle.
				if (backtrack(i, visitingStatus))
				{
					return false;
				}
			}
			
			return true;
		}
		
	private:

		vector<vector<int>> mGraph;

		enum State
		{
			Visiting,
			Visited,
			Unknown
		};

		// Returns true if there's a cycle.
		bool backtrack(int currentCourse, vector<State>& visitingStatus)
		{
			if (visitingStatus[currentCourse] == State::Visiting)
			{
				return true;
			}
			else if (visitingStatus[currentCourse] == State::Visited)
			{
				return false;
			}
			
			visitingStatus[currentCourse] = State::Visiting;
			for (int course : mGraph[currentCourse])
			{
				if (backtrack(course, visitingStatus))
				{
					return true;
				}
			}
			visitingStatus[currentCourse] = State::Visited;
			
			return false;
		}

};
