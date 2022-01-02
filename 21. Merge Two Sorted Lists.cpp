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
    ListNode* curNode = &dummy;

    while (l1 and l2) {
        if (l1->val < l2->val) {
            curNode->next = l1;
            l1 = l1->next;
        } else {
            curNode->next = l2;
            l2 = l2->next;
        }

        curNode = curNode->next;
    }

    curNode->next = l1 ? l1 : l2;

    return dummy.next;
}
