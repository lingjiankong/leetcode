// ***
//
// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
// Example:
//
// Given the sorted linked list: [-10,-3,0,5,9],
//
// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
//
//       0
//      / \
//    -3   9
//    /   /
//  -10  5
//
// ***
//
// See also 108. Covert Sorted Array to Binary Search Tree. These two questions are essentially the same.
// The only difference is how you find the mid element of an array and of a linked list.
//
// See also 234. Palindrome Linked List for intuition on calculating the mid of a linked list.
class Solution
{

	public:

		TreeNode* sortedListToBST(ListNode* head)
		{
			return sortedListToBST(head, nullptr);
		}

	private:

		TreeNode* sortedListToBST(ListNode* head, ListNode* tail)
		{
			if (head == tail)
			{
				return nullptr;
			}

			ListNode* mid = findMid(head, tail);

			TreeNode* root = new TreeNode(mid->val);
			root->left = sortedListToBST(head, mid);
			root->right = sortedListToBST(mid->next, tail);

			return root;

		}

		ListNode* findMid(ListNode* head, ListNode* tail)
		{
			ListNode* slow = head;
			ListNode* fast = head;

			while (fast != tail && fast->next != tail)
			{
				slow = slow->next;
				fast = fast->next->next;
			}

			return slow;
		}

};
