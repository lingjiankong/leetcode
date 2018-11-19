// Use a priority_queue which stores {abs(node->val - target), node->val}.
// Traverse the tree in order and add element to that priority queue, if the queue size is
// larger than k, then pop the element (the element being popped is the once with the largest
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
				result.push_back(mPriorityQueue.top().second);
				mPriorityQueue.pop();
			}

			return result;
		}
	
	private:

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
