// ***
//
// Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
//
// Note:
//
// Given target value is a floating point.
// You may assume k is always valid, that is: k ≤ total nodes.
// You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
//
// Example:
//
// Input: root = [4,2,5,1,3], target = 3.714286, and k = 2
//
//     4
//    / \
//   2   5
//  / \
// 1   3
//
// Output: [4,3]
//
// ***

class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        inorder(root, target, k);

        vector<int> res;
        while (not _pq.empty()) {
            res.push_back(_pq.top().second);
            _pq.pop();
        }

        return res;
    }

private:
    // Default C++ priority_queue is max queue using std::less<int> i.e. Max element has the highest priority.
    priority_queue<pair<double, int>> _pq;

    void inorder(TreeNode* node, double target, int k) {
        if (!node) {
            return;
        }

        inorder(node->left, target, k);

        _pq.push({abs(node->val - target), node->val});
        if (_pq.size() > k) {
            _pq.pop();
        }

        inorder(node->right, target, k);
    }
};
