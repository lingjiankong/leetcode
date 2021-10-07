// ***
//
// You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor
// its parent, itself, and its immediate children.
//
// Return the minimum number of cameras needed to monitor all nodes of the tree.
//
//
// Example 1:
//
// Input: root = [0,0,null,0,0]
// Output: 1
// Explanation: One camera is enough to monitor all nodes if placed as shown.
//
//
// Example 2:
//
// Input: root = [0,0,null,0,null,0,null,null,0]
// Output: 2
// Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid
// configurations of camera placement.
//
//
// Constraints:
//
// The number of nodes in the tree is in the range [1, 1000].
// Node.val == 0
//
// ***

class Solution {
public:
    enum State { NONE, COVERED, CAMERA };

    int minCameraCover(TreeNode* root) {
        if (_postorder(root) == NONE) {
            ++_minCams;
        };

        return _minCams;
    }

private:
    int _minCams = 0;

    State _postorder(TreeNode* root) {
        // Postorder traverse the tree bottom up.
        // You want to place cameras on the parent node of a leaf node.
        //                  CAMERA
        //               /          \
        //           NONE            NONE   <- leaf nodes
        //          /    \          /    \
        //      COVERED COVERED COVERED COVERED  <- nullptrs
        if (not root) {
            return COVERED;
        }

        State left = _postorder(root->left);
        State right = _postorder(root->right);

        if (left == NONE or right == NONE) {
            ++_minCams;
            return CAMERA;
        }

        if (left == CAMERA or right == CAMERA) {
            return COVERED;
        }

        return NONE;
    }
};
