// ***
//
// Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
// Note that the row index starts from 0.
//
// In Pascal's triangle, each number is the sum of the two numbers directly above it.
//
// Example:
//
// Input: 3
// Output: [1,3,3,1]
//
// ***
//
// [
//  [1],
//  [1,1],
//  [1,2,1],
//  [1,3,3,1],
//  [1,4,6,4,1]
// ]

// Can be solved same way as in 118. Pascal Triangle.
vector<int> getRow(int rowIndex) {
    vector<vector<int>> triangle;

    int total_levels = rowIndex + 1;
    for (int i = 0; i < total_levels; ++i) {
        triangle.push_back(vector<int>(i + 1, 1));

        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    return triangle[rowIndex];
}

