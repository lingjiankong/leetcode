// ***
//
// Two elements of a binary search tree (BST) are swapped by mistake.
//
// Recover the tree without changing its structure.
//
// Example 1:
//
// Input: [1,3,null,null,2]
//
//    1
//   /
//  3
//   \
//    2
//
// Output: [3,1,null,null,2]
//
//    3
//   /
//  1
//   \
//    2
// Example 2:
//
// Input: [3,1,4,null,null,2]
//
//   3
//  / \
// 1   4
//    /
//   2
//
// Output: [2,1,4,null,null,3]
//
//   2
//  / \
// 1   4
//    /
//   3
// Follow up:
//
// A solution using O(n) space is pretty straight forward.
// Could you devise a constant space solution?
//
// ***

// O(n) space complexity.
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        vector<int> nodeVals;

        _inorder(root, nodes, nodeVals);

        sort(nodeVals.begin(), nodeVals.end());
        for (int i = 0; i < nodes.size(); ++i) {
            nodes[i]->val = nodeVals[i];
        }
    }

private:
    void _inorder(TreeNode* root, vector<TreeNode*>& nodes, vector<int>& nodeVals) {
        if (not root) {
            return;
        }
        _inorder(root->left, nodes, nodeVals);

        nodes.push_back(root);
        nodeVals.push_back(root->val);

        _inorder(root->right, nodes, nodeVals);
    }
};

// O(1) space complexity not counting recursion.
// Since we know exactly one pair has been swapped, we can find that pair.
class Solution {
public:
    void recoverTree(TreeNode* root) {
        _inorder(root);
        swap(first->val, second->val);
    }

    void _inorder(TreeNode* root) {
        if (not root) {
            return;
        }
        _inorder(root->left);

        // We know only two elements have been swapped, so if prev->val > root->val,
        // then prev is a misplaced node, assign it to first;
        // current root is also a misplaced node, assign it to second.
        if (prev and prev->val > root->val) {
            if (not first) {
                first = prev;
            }
            // Note that "first" will not change once assigned (because the first prev we encounter which prev->val
            // > root->val is a misplaced node). However, we will keep assigning current root to "second" as long as
            // prev->val > root->val since current root is also a misplaced node (we only have a pair of misplaced
            // node).
            second = root;
        }
        prev = root;

        _inorder(root->right);
    }

private:
    // prev: previous element during in order traversal
    // first: first misplaced node
    // second: second misplaced node
    TreeNode *prev = nullptr, *first = nullptr, *second = nullptr;
};
