// See a very similar question: 257. Binary Tree Paths.
class Solution
{

public:

    int sumNumbers(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }

        dfs(root, "");

        return total;
    }

private:

    int total;

    void dfs(TreeNode* node, string number)
    {
        if (!node)
        {
            return;
        }

        number += to_string(node->val);

        if (!node->left && !node->right)
        {
            total += stoi(number);
        }

        dfs(node->left, number);
        dfs(node->right, number);
    }

};

// Same idea without using pricate variable.
class Solution
{

	public:

		int sumNumbers(TreeNode* root)
		{
			if (!root)
			{
				return 0;
			}

			int total = dfs(root, "");

			return total;
		}

	private:

		int dfs(TreeNode* node, string number)
		{
			if (!node)
			{
				return 0;
			}

			int total = 0;

			number += to_string(node->val);

			if (!node->left && !node->right)
			{
				total += stoi(number);
			}

			total += dfs(node->left, number) + dfs(node->right, number);

			return total;
		}

};
