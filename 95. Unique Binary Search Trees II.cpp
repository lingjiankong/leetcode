// Given nodes [1, 2, 3, 4, 5, 6]
// If 4 is the root node, then the left subtree can be formed using [1, 2, 3].
// right subtree can be formed using [3, 6].
// Do it recursively using pointer [start, end] (inclusive).
// This one is hard... Took me some time. Read the code and think about it.
class Solution
{

	public:

		vector<TreeNode*> generateTrees(int n)
		{
			if (n == 0)
			{
				return {};
			}

			// [start, end] is inclusive.
			return generateTrees(1, n);
		}

	private:
		
		vector<TreeNode*> generateTrees(int start, int end)
		{
			if (start > end)
			{
				return { nullptr };
			}

			vector<TreeNode*> toReturn;

			// Pick a root i.
			for (int i = start; i <= end; ++i)
			{
				// All possible left node if i is chosen to be the root node.
				vector<TreeNode*> leftNodeCandidates = generateTrees(start, i - 1);

				// All possible right node if i is chosen to be the root node.
				vector<TreeNode*> rightNodeCandidates = generateTrees(i + 1, end);

				// Connect the root with its left and right nodes and push it to result.
				for (auto leftNode : leftNodeCandidates)
				{
					for (auto rightNode : rightNodeCandidates)
					{
						TreeNode* rootNode = new TreeNode(i);
						rootNode->left = leftNode;	
						rootNode->right = rightNode;

						toReturn.push_back(rootNode);
					}
				}
			}

			return toReturn;
		}

};
