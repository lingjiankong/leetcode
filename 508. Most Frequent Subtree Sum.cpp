// ***
//
// Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with
// the highest frequency in any order.
//
// The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node
// (including the node itself).
//
//
// Example 1:
//
// Input: root = [5,2,-3]
// Output: [2,-3,4]
//
//
// Example 2:
//
// Input: root = [5,2,-5]
// Output: [2]
//
// ***

// By using postorder, you can calculate the sum of every subtree.
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        treeSum(root);

        vector<int> res;
        for (auto& e : _sum2Freq) {
            if (e.second == _maxFreq) {
                res.push_back(e.first);
            }
        }
        return res;
    }

private:
    unordered_map<int, int> _sum2Freq;

    int _maxFreq = 0;

    int treeSum(TreeNode* root) {
        if (not root) {
            return 0;
        }

        int leftSum = treeSum(root->left);
        int rightSum = treeSum(root->right);

        int sum = root->val + leftSum + rightSum;
        _maxFreq = max(++_sum2Freq[sum], _maxFreq);
        return sum;
    }
};

