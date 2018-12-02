// ***
//
// Remove all elements from a linked list of integers that have value val.
// 
// Example:
// 
// Input:  1->2->6->3->4->5->6, val = 6
// Output: 1->2->3->4->5
//
// ***
ListNode* removeElements(ListNode* head, int val)
{
	ListNode dummy = ListNode(0);
	dummy.next = head;

	ListNode* prevNode = &dummy;

	while (prevNode->next)
	{
		if (prevNode->next->val == val)
		{
			ListNode* toBeDeleted = prevNode->next;
			prevNode->next = prevNode->next->next;
			delete toBeDeleted;
		}
		else
		{
			prevNode = prevNode->next;
		}
	}

	return dummy.next;
}
