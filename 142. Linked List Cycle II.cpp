// ***
// 
// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
// 
// Note: Do not modify the linked list.
// 
// ***
//
// See the picture at http://www.cnblogs.com/hiddenfox/p/3408931.html that explains the theory.
// When meet, slow has travelled a + b, fast has travelled a + b + c + b.
// => 2(a+b) = a+b+c+d => 2a = a+c => a = c => the distance from head to cycle start and the distance from meet point to cycle start
// MUST be the same. Start from head and the meet point, when they are equal it is the cycle start.
ListNode *detectCycle(ListNode *head)
{
	ListNode *slow = head, *fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		// Break when slow meets fast, we've now found a cycle.
		// Note the meet point is somewhere inside the cycle, it is NOT where the cycle starts.
		if (slow == fast)
		{
			break;
		}
	}

	// There is no cycle in this case.
	if (!fast || !fast->next)
	{
		return nullptr;
	}

	// It is guaranteed that the distance from head to cycle start and the distance from
	// meet point to cycle start MUST be the same.
	// Start from head and the meet point, when they are equal it is the cycle start.
	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}
