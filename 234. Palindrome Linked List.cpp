bool isPalindrome(ListNode* head)
{

	if (!head || !head->next)
	{
		return true;
	}

	// Find middle element
	// slow is now the middle element:
	// If the list is 1-2-3-4-5 the middle element is 3
	// If the list is 1-2-3-4 the middle element is 2
	//
	// If the while condition was while (fast && fast->next)
	// then the mid element will be on the right part if even number of elements/
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	// Reverse second half of the linkedlist
	ListNode* head2 = slow->next; // head of second half

	ListNode* prevNode = nullptr;
	while (head2)
	{
		ListNode* nextNode = head2->next;
		head2->next = prevNode;
		prevNode = head2;
		head2 = nextNode;
	}

	// Note here head2 is a nullptr now (because while (head2) is evaluated false)
	// Therefore we return head2 = prevNode, the last element in the linkedlist
	head2 = prevNode;

	while (head && head2)
	{
		if (head->val != head2->val)
		{
			return false;
		}

		head = head->next;
		head2 = head2->next;
	}

	return true;
}
