// ***
//
// There are a total of n courses you have to take, labeled from 0 to n-1.
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed
// as a pair: [0,1]. Given the total number of courses and a list of prerequisite pairs, return the ordering of courses
// you should take to finish all courses. There may be multiple correct orders, you just need to return one of them. If
// it is impossible to finish all courses, return an empty array.
//
// Example 1:
//
// Input: 2, [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished
//              course 0. So the correct course order is [0,1] .
// Example 2:
//
// Input: 4, [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,1,2,3] or [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both
//              courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
//              So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
//
// ***
//
// See 207. Course Schedule. The code is almost the same.
// This code stores one additional information: courseOrder, which stores the course after topological sort.
// i.e. postorder traversal of graph
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Construct the graph
        vector<vector<int>> graph(numCourses);
        for (vector<int>& course : prerequisites) {
            graph[course[1]].push_back(course[0]);
        }

        // Initialize the initial states for all courses to be UNVISITED.
        vector<State> states(numCourses, State::UNVISITED);
        vector<int> courseOrder;
        for (int i = 0; i < numCourses; ++i) {
            if (hasCycle(i, states, courseOrder, graph)) {
                return {};
            }
        }

        // courseOrder stores the post order result of the graph after topologocial sort.
        // Therefore to get the course order you need to reverse it.
        reverse(courseOrder.begin(), courseOrder.end());

        return courseOrder;
    }

private:
    enum State { UNVISITED, VISITING, VISITED };

    bool hasCycle(int curCourse, vector<State>& states, vector<int>& courseOrder, const vector<vector<int>>& graph) {
        if (states[curCourse] == State::VISITING) {
            return true;  // has cycle
        } else if (states[curCourse] == State::VISITED) {
            return false;
        }

        states[curCourse] = State::VISITING;
        for (int course : graph[curCourse]) {
            if (hasCycle(course, states, courseOrder, graph)) {
                return true;
            }
        }
        states[curCourse] = State::VISITED;

        // Postorder traversal of graph.
        // The first course that you add to courseOrder is the first course which you've done traversing.
        courseOrder.push_back(curCourse);

        return false;
    }
};

