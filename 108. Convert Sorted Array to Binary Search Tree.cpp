// The root value of a binary search tree is greater than its left subtree and
// less than its right subtree. That is, the root of a binary serach tree is nums[mid].
// We construct the root first, then recursively construct its left and right subtrees
//
// Why mid = low + (high-low-1)/2 ?
// Unlike binary search, where we often set high to be the index of the last element
// and calculate the mid index using mid = low + (high-low)/2,
// here, high is ONE PAST the index of the last elements.
//
// Remember you can calculate the mid index of an array using two ways:
// 1. (nums.size() - 1) / 2 : mid is on the left part if even elements (I usually do this).
// 2. nums.size() / 2 : mid is on the right part if even elements.
//
// In this case, we are just calculating the mid using the first way.
// Note, if you calculate the mid using second way (mid = low + (high-low)/2), you answer still pass,
// the constructed binary search tree is still valid, just looks different.
class Solution
{

	public:

		TreeNode* sortedArrayToBST(const vector<int>& nums)
		{
			int low = 0;
			int high = nums.size();
			return preOrder(nums, low, high);
		}

	private:
		
		TreeNode* preOrder(const vector<int>& nums, int low, int high)
		{
			if (low >= high)
			{
				return nullptr;
			}

			int mid = low + (high-low-1)/2;

			TreeNode root = new TreeNode(nums[mid]);
			root->left = preOrder(nums, low, mid);
			root->right = preOrder(nums, mid+1, high);

			return root;
		}

};
