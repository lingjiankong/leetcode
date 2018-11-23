ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode dummy = ListNode(0);
	ListNode* current = &dummy;
	int carry = 0;

	while (l1 || l2 || carry)
	{
		int sum = 0;

		if (l1)
		{
			sum += l1->val;
			l1 = l1->next;
		}

		if (l2)
		{
			sum += l2->val;
			l2 = l2->next;
		}

		if (carry)
		{
			sum += 1;
		}

		current->next = new ListNode(sum % 10);
		carry = sum / 10;
		current = current->next;
	}

	return dummy.next;
}
