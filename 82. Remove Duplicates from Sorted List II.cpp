// ***
//
// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
// 
// Example 1:
// 
// Input: 1->2->3->3->4->4->5
// Output: 1->2->5
//
// Example 2:
// Input: 1->1->1->2->3
// Output: 2->3
//
// ***
//
// dummy -> 1 -> 1 -> 1 -> 1 -> 1 -> 2 -> 2 -> 2 -> 2 -> 3 -> 4 -> 4 -> 5
// ^        ^                   ^
// prev	    prev->next          current
//
// dummy -> 1 -> 1 -> 1 -> 1 -> 1 -> 2 -> 2 -> 2 -> 2 -> 3 -> 4 -> 4 -> 5
// ^                                 ^              ^
// prev                              prev->next     current
ListNode* deleteDuplicates(ListNode* head)
{
	if (!head || !head->next)
	{
		return head;
	}

	ListNode dummy(0);
	dummy.next = head;

	ListNode* prevNode = &dummy;

	while (prevNode->next)
	{
		ListNode* currentNode = prevNode->next;
		while (currentNode->next && currentNode->next->val == prevNode->next->val)
		{
			currentNode = currentNode->next;
		}

		// If these two does not point to the same address, we were inside the while loop and have seen duplicates. Set prev->next to cur->next but do not update prev yet!
		// Because you may keep seeing all duplciates and in that case we still want prev to stay at the original place.
		if (currentNode != prevNode->next)
		{
			prevNode->next = currentNode->next;
		}
		// Else, we update prevNode only if you have not seen duplicates.
		else
		{
			prevNode = prevNode->next;
		}
	}

	return dummy.next;
}
