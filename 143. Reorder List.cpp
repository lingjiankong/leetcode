// ***
//
// Given a singly linked list L: L0→ L1→ …→ Ln-1→ Ln,
// reorder it to: L0→ Ln→ L1→ Ln-1→ L2→ Ln-2→ …
// 
// You may not modify the values in the list's nodes, only nodes itself may be changed.
// 
// Example 1:
// 
// Given 1->2->3->4, reorder it to 1->4->2->3.
//
// Example 2:
// 
// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
//
// ***
//
// This is a good question that tests three separate knowledge. Makes sense.
void reorderList(ListNode *head)
{
	if (!head || !head->next || !head->next->next)
	{
		return;
	}

	// 1. Break the linked list at the mid point.
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	ListNode* mid = slow->next;
	slow->next = nullptr;

	// 2. Reverse the second half of the linked list.
	ListNode* prevNode = nullptr;
	while (mid)
	{
		ListNode* nextNode = mid->next;
		mid->next = prevNode;
		prevNode = mid;
		mid = nextNode;
	}

	// 3. Add the reversed second half of the linked list to the first half of the linked list.
	// prevNode is now the reversed head of the right half of the linked list.
	ListNode* rightHead = prevNode;
	while (head && rightHead)
	{
		ListNode* nextNode = head->next;
		head->next = rightHead;
		rightHead = rightHead->next;
		head->next->next = nextNode;
		head = nextNode;
	}
}
