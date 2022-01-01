// ***
//
// Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a
// subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could
// also be considered as a subtree of itself.
//
// Example 1:
// Given tree s:
//
//      3
//     / \
//    4   5
//   / \
//  1   2
// Given tree t:
//    4
//   / \
//  1   2
// Return true, because t has the same structure and node values with a subtree of s.
//
// Example 2:
// Given tree s:
//
//      3
//     / \
//    4   5
//   / \
//  1   2
//     /
//    0
// Given tree t:
//    4
//   / \
//  1   2
// Return false.
//
// ***

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        // if s is a nullptr, then t should not be considered as a subtree of s.
        // (given in the problem, t is non-empty).
        if (!s) {
            return false;
        }

        if (_isSameTree(s, t)) {
            return true;
        }

        return isSubtree(s->left, t) or isSubtree(s->right, t);
    }

private:
    bool _isSameTree(TreeNode* p, TreeNode* q) {
        if (!p and !q) {
            return true;
        }
        if (!p or !q) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }

        return _isSameTree(p->left, q->left) and _isSameTree(p->right, q->right);
    }
};
