// ***
//
// Remove all elements from a linked list of integers that have value val.
//
// Example:
//
// Input:  1->2->6->3->4->5->6, val = 6
// Output: 1->2->3->4->5
//
// ***

ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode* prevNode = &dummy;

    while (prevNode->next) {
        if (prevNode->next->val == val) {
            ListNode* toBeDeleted = prevNode->next;
            prevNode->next = prevNode->next->next;  // prevNode itself is anchored. Update its next ptr only.
            delete toBeDeleted;
        } else {
            prevNode = prevNode->next;  // advance prevNode
        }
    }

    return dummy.next;
}
