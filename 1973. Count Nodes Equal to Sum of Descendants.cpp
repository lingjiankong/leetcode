// ***
//
// Given the root of a binary tree, return the number of nodes where the value of the node is equal to the sum of the
// values of its descendants.
//
// A descendant of a node x is any node that is on the path from node x to some leaf node. The sum is considered to be 0
// if the node has no descendants.
//
// Input: root = [10,3,4,2,1]
// Output: 2
//
// Explanation:
// For the node with value 10: The sum of its descendants is 3+4+2+1 = 10.
// For the node with value 3: The sum of its descendants is 2+1 = 3.
//
// ***

class Solution {
public:
    int equalToDescendants(TreeNode* root) {
        treeSum(root);
        return _count;
    }

private:
    long treeSum(TreeNode* root) {
        if (not root) {
            return 0;
        }

        long leftSum = treeSum(root->left);
        long rightSum = treeSum(root->right);

        if (root->val == leftSum + rightSum) {
            ++_count;
        }

        return root->val + leftSum + rightSum;
    }

    int _count = 0;
};

