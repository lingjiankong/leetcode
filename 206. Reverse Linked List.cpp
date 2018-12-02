// ***
//
// Reverse a singly linked list.
// 
// Example:
// 
// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
//
// ***
//
// Iterative.
ListNode* reverseList(ListNode* head)
{
	ListNode* prevNode = nullptr;

	while (head)
	{
		ListNode* nextNode = head->next;
		head->next = prevNode;
		prevNode = head;
		head = nextNode;
	}

	return prevNode;
}

// Recursive. Harder to understand.
// Visualize the case when you've reached the last node.
ListNode* reverseList(ListNode* head)
{
	if (!head || !head->next)
	{
		return head;
	}

	ListNode *newHead = reverseList(head->next);

	head->next->next = head;
	head->next = nullptr;

	return newHead;
}
