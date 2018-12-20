// ***
//
// Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
// 
// Note:
// 
// Given target value is a floating point.
// You are guaranteed to have only one unique value in the BST that is closest to the target.
// Example:
// 
// Input: root = [4,2,5,1,3], target = 3.714286
// 
//     4
//    / \
//   2   5
//  / \
// 1   3
// 
// Output: 4
//
// ***
//
// Simply use the property of binary search tree.
int closestValue(TreeNode* root, double target)
{
	int closestNodeValue = root->val;

	while (root)
	{
		// Compare and see if we should update closestNodeValue.
		if (abs(root->val - target) < abs(closestNodeValue - target))
		{
			closestNodeValue = root->val;
		}

		root = root->val < target ? root->right : root->left;
	}

	return closestNodeValue;
}
