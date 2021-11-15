// ***
//
// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or
// equal to x. You should preserve the original relative order of the nodes in each of the two partitions.
//
// Example:
//
// Input: head = 1->4->3->2->5->2, x = 3
// Output: 1->2->2->4->3->5
//
// ***
//
// The solution is very intuitive. dummyLeft chains all elements smaller than x, dummyRight chains all elements beggier
// than x. Connect the tail of dummyLeft with the head of dummyRight in the end to form the partitioned LinkedList.

ListNode *partition(ListNode *head, int x) {
    ListNode dummyLeft(0), dummyRight(0);

    ListNode *p1 = &dummyLeft, *p2 = &dummyRight;

    while (head) {
        if (head->val < x) {
            p1->next = head;
            p1 = p1->next;
        } else {
            p2->next = head;
            p2 = p2->next;
        }

        head = head->next;
    }

    p1->next = dummyRight.next;
    p2->next = nullptr;

    return dummyLeft.next;
}
