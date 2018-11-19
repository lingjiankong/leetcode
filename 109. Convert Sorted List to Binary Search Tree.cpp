// See also 108. Covert Sorted Array to Binary Search Tree,
// These two questions are essentially the same, the only difference is
// how you find the mid element of an array and of a linked list.
// Here the mid element will be on the left part if we have even number of elements.
//
// Note in both questions, the right (tail) is one past the last element we are interested in,
// and is not included in the mid calculation.
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

			while (fast->next != tail && fast->next->next != tail)
			{
				slow = slow->next;
				fast = fast->next->next;
			}

			return slow;
		}

};
