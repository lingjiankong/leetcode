// ***
//
// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes
// of the first two lists.
//
// Example:
//
// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4
//
// ***

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* cur = &dummy;

    while (l1 and l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }

        cur = cur->next;
    }

    cur->next = l1 ? l1 : l2;

    return dummy.next;
}
