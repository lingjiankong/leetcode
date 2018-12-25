// ***
//
// Given a linked list, remove the n-th node from the end of list and return its head.
// 
// Example:
// Given linked list: 1->2->3->4->5, and n = 2.
// 
// After removing the second node from the end, the linked list becomes 1->2->3->5.
//
// Note: Given n will always be valid.
//
// ***
ListNode* removeNthFromEnd(ListNode* head, int n)
{
	if (!head->next)
	{
		return nullptr;
	}

	// pre->next is the node we would like to remove.
	ListNode *pre = head, *cur = head;

	for (int i = 0; i < n; ++i)
	{
		cur = cur->next;
	}

	// cur has reached one past the last element (the nullptr)
	// In this case number n given is the same as number of nodes in the linked list.
	// which means we need to remove the first element in the LinkedList, so simply return the second element as the new head.
	if (!cur)
	{
		return head->next;
	}

	// Otherwise, increment pre and cur together to the right,
	// until cur->next == nullptr, at this point pre->next reached the element which we want to remove.
	while (cur->next)
	{
		cur = cur->next;
		pre = pre->next;
	}

	ListNode* toBeDeleted = pre->next;
	pre->next = pre->next->next;
	delete toBeDeleted;

	return head;
}
