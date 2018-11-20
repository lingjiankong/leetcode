// It took me a long time to understand this question, see
// http://www.cnblogs.com/grandyang/p/5327635.html for explanation in Chinese.
//
// low is the parent node which current subtree is low's right subtree.
// We know that for binary search tree, all values in the right subtree must be greater than low,
// so if val < low, we just return false.
// low was initialized to INT_MIN to simulate an imaginary one.
//
// Preorder traversal of a binary search tree should print decreasing element (meaning we are still on the left subtree).
// In this case, val is less than the last top element in nodeStack, so we simply push val to nodeStack.
// If we see an element bigger than previous one, this means we are on the right subtree of some node along the way,
// BUT we need to figure out to which node this right subtree is (this is what the while loop is doing),
// and update our low so that all traversal of this "right subtree" to that node should never be smaller than the value of the node.
bool verifyPreorder(vector<int>& preorder)
{
	int low = INT_MIN;
	
	stack<int> nodeStack;

	for (int val : preorder)
	{
		if (val < low)
		{
			return false;
		}

		while (!nodeStack.empty() && val > nodeStack.top())
		{
			low = nodeStack.top();
			nodeStack.pop();
		}

		nodeStack.push(val);
	}

	return true;
}

// Same idea without using a stack.
bool verifyPreorder(vector<int>& preorder)
{
	int low = INT_MIN, i = -1;

	for (int val : preorder)
	{
		if (val < low) 
		{
			return false;
		}

		while (i >= 0 && val > preorder[i])
		{
			low = preorder[i--];
		}

		preorder[++i] = val;
	}

	return true;
}
