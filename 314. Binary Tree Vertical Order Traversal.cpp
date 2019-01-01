// ***
//
// Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
// 
// If two nodes are in the same row and column, the order should be from left to right.
// 
// Examples 1:
// 
// Input: [3,9,20,null,null,15,7]
// 
//    3
//   /\
//  /  \
//  9  20
//     /\
//    /  \
//   15   7 
// 
// Output:
// 
// [
//   [9],
//   [3,15],
//   [20],
//   [7]
// ]
// Examples 2:
// 
// Input: [3,9,8,4,0,1,7]
// 
//      3
//     /\
//    /  \
//    9   8
//   /\  /\
//  /  \/  \
//  4  01   7 
// 
// Output:
// 
// [
//   [4],
//   [9],
//   [3,0,1],
//   [8],
//   [7]
// ]
// Examples 3:
// 
// Input: [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5)
// 
//      3
//     /\
//    /  \
//    9   8
//   /\  /\
//  /  \/  \
//  4  01   7
//     /\
//    /  \
//    5   2
// 
// Output:
// 
// [
//   [4],
//   [9,5],
//   [3,0,1],
//   [8,2],
//   [7]
// ]
//
// ***
//
// See also 102. Binary Tree Level Order Traversal.
//
// Level order (horizontally) traverse the tree,
// in the queue for level order traversal, also store the current vertical level for each node:
// For a left node, vertical level -= 1,
// for a right node node, vertical level += 1.
// Maintain an tree map<int, vector<int>> levelToNodes, which stores each vertical level and all nodes at that level.
//
// Why do we need to maintain an tree map levelToNodes?
// Because unlike horizontal level order, initially you don't know what the "0th" vertial level is,
// so you can't use index to push to vector. We have to traverse through levelToNodes in the end
// and push each vector at different vertical level to toReturn in the end.
vector<vector<int>> verticalOrder(TreeNode* root)
{
	if (!root)
	{
		return {};
	}

	map<int, vector<int>> levelToNodes;

	// Stores node as well as that node's vertical level.
	queue<pair<TreeNode*, int>> nodeQueue;
	nodeQueue.push({root, 0});

	while (!nodeQueue.empty())
	{
		auto nodeToLevel = nodeQueue.front(); nodeQueue.pop();

		TreeNode* node = nodeToLevel.first;
		int verticalLevel = nodeToLevel.second;

		levelToNodes[verticalLevel].push_back(node->val);

		if (node->left)
		{
			nodeQueue.push({node->left, verticalLevel - 1});
		}
		
		if (node->right)
		{
			nodeQueue.push({node->right, verticalLevel + 1});
		}
	}

	vector<vector<int>> toReturn;
	for (auto element : levelToNodes)
	{
		vector<int> sameLevelNodes = element.second;
		toReturn.push_back(sameLevelNodes);
	}

	return toReturn;
}
