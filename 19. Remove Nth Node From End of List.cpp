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

	// Pre is the position of the node we want to remove.
	ListNode *pre = head, *cur = head;

	for (int i = 0; i < n; ++i)
	{
		cur = cur->next;
	}

	// cur has reached on past the next element (thee nullptr)
	// In this case we need to remove the first element in the LinkedList, so simply return the second element.
	if (!cur)
	{
		return head->next;
	}

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
