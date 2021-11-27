// ***
//
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array
// prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take
// course ai.
//
// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.
//
//
// Example 1:
//
// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0. So it is possible.
//
//
// Example 2:
//
// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So
// it is impossible.
//
//
// Constraints:
//
// 1 <= numCourses <= 105
// 0 <= prerequisites.length <= 5000
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// All the pairs prerequisites[i] are unique.
//
// ***

// Typical topological sort.
// This question is the same as asking us to detect whether there's loop in a graph.
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Construct the graph
        vector<vector<int>> graph(numCourses);
        for (vector<int>& course : prerequisites) {
            graph[course[1]].push_back(course[0]);
        }

        // Initialize the initial states for all courses to be UNVISITED.
        vector<State> states(numCourses, State::UNVISITED);
        for (int i = 0; i < numCourses; ++i) {
            // If hasCycle returns true then there's a cycle.
            if (hasCycle(i, states, graph)) {
                return false;
            }
        }

        return true;
    }

private:
    enum State { UNVISITED, VISITING, VISITED };

    // Returns true if there's a cycle.
    bool hasCycle(int curCourse, vector<State>& states, const vector<vector<int>>& graph) {
        if (states[curCourse] == State::VISITING) {
            return true;  // has cycle
        }
        if (states[curCourse] == State::VISITED) {
            return false;
        }

        // Neither VISITING nor VISITED. This course is unvisited.
        states[curCourse] = State::VISITING;
        for (int course : graph[curCourse]) {
            if (hasCycle(course, states, graph)) {
                return true;
            }
        }
        states[curCourse] = State::VISITED;

        return false;
    }
};
