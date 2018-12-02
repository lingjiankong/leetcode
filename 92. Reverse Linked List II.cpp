// ***
//
// Reverse a linked list from position m to n. Do it in one-pass.
// 
// Note: 1 ≤ m ≤ n ≤ length of list.
// 
// Example:
// 
// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL
//
// ***
//
// This question is rediculous. Took me more than two hours.
// You want to form something like the following.
//
//      ______
//      |    |
//      |    v
// 1    2    3 -> 4 -> 5 -> 6 -> 7
// |    ^
// |____|
//
// ^    ^    ^
// prev      next
//      current
//
//      ___________
//      |         |
//      |         v
// 1    2 <- 3    4 -> 5 -> 6 -> 7
// |         ^
// |_________|
//
// ^    ^         ^
// prev current   next
//      ________________
//      |              |
//      |              v
// 1    2 <- 3 <- 4    5 -> 6 -> 7
// |              ^
// |______________|
//
// ^    ^              ^
// prev current        next
//
// prev and current do not change, only next changes.

ListNode* reverseBetween(ListNode* head, int m, int n)
{
	if (!head)
	{
		return nullptr;
	}

	ListNode dummy = ListNode(0);
	dummy.next = head;

	ListNode* prevNode = &dummy;

	for (int i = 1; i < m; ++i)
	{
		prevNode = prevNode->next;
	}

	ListNode* currentNode = prevNode->next;
	ListNode* nextNode = prevNode->next->next;

	int numOperations = n - m;
	while (numOperations--)
	{
		currentNode->next = nextNode->next;
		nextNode->next = prevNode->next;
		prevNode->next = nextNode;
		nextNode = currentNode->next;
	}

	return dummy.next;
}
