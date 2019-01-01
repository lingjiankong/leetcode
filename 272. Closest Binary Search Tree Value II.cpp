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


// Use a priority_queue which stores a pair<double, int> of {abs(node->val - target), node->val}.
// Traverse the tree in order and add element to that priority_queue, if the queue size is
// larger than k, then pop the element (the element being popped is the ones with the largest
// absolute difference between node value and target).
class Solution
{

	public:

		vector<int> closestKValues(TreeNode* root, double target, int k)
		{
			vector<int> result;

			inOrder(root, target, k);

			while (!mPriorityQueue.empty())
			{
				result.push_back(mPriorityQueue.top().second); mPriorityQueue.pop();
			}

			return result;
		}
	
	private:

		// Default C++ priority_queue is max queue using std::less<int> i.e. Max element has the highest priority.
		priority_queue<pair<double, int>> mPriorityQueue;

		void inOrder(TreeNode* node, double target, int k)
		{
			if (!node)
			{
				return;
			}

			inOrder(node->left, target, k);

			mPriorityQueue.push({abs(node->val - target), node->val});
			if (mPriorityQueue.size() > k)
			{
				mPriorityQueue.pop();
			}

			inOrder(node->right, target, k);
		}

};
