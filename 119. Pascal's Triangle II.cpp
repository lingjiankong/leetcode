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

vector<int> getRow(int rowIndex) {
    vector<int> res(rowIndex + 1, 1);

    for (int i = 0; i < rowIndex; ++i) {
        // This trick is important, assign res[j] = res[j-1] + res[j] from end to beginning.
        // This way we don't need to create a temp variable for res[j] as if
        // we were doing the operation from beginning to end
        for (int j = i; j > 0; --j) {
            res[j] = res[j - 1] + res[j];
        }
    }

    return res;
}
