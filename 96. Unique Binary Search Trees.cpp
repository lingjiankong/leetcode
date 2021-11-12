// ***
//
// Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
//
// Example:
//
// Input: 3
// Output: 5
// Explanation:
// Given n = 3, there are a total of 5 unique BST's:
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
//
// ***
//
// See https://www.youtube.com/watch?v=HWJEMKWzy-Q for very a clear explanation.
// You need to remember the intuition.
//
// dp stores how many unique BSTs can be formed using n nodes.
// We also define 1 unique BST can be formed using 0 node, because an empty tree is still a valid BST.
// That is, we initialize dp[0] = 1 and dp[1] = 1.
//
// Now, for example when we want to see how many unique BSTs can be formed using 3 nodes:
// Node 1, 2, 3 can all be the root.
// Say now we want node 1 to be the root, in this case, all nodes should be on the right because 1 is the smallest,
// so the leftsubtree should have 0 node, right subtree should have 2 nodes.
// so the total number of tree when node 1 is the root is dp[0] * dp[2]
//
// Similar argument applies when node 2 is the root and node 3 is the root.
// We just need to sum the number of total trees up.
// The transition equation for n = 3 is
// dp[3] = dp[0] * dp[2]　　　(when 1 is the root)
//       + dp[1] * dp[1]　　  (when 2 is the root)
//       + dp[2] * dp[0]　　  (when 3 is the root)
//
//                     1                        n = 1
//
//                 2        1                   n = 2
//                /          \
//               1            2
//
//    1         3     3      2      1           n = 3
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
//
//
//                     1                           n = 1
//                    / \
//               dp[0]   dp[0]
//
//                 1             2                 n = 2
//                / \           / \
//           dp[0]   dp[1] dp[1]   dp[0]
//
//       1              2              3           n = 3
//      / \            / \            / \
// dp[0]  dp[2]   dp[1]   dp[1]  dp[2]   dp[0]

int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[n];
}
