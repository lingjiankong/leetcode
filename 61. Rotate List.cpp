// ***
//
// Given a linked list, rotate the list to the right by k places, where k is non-negative.
//
// Example 1:
//
// Input: 1->2->3->4->5->NULL, k = 2
// Output: 4->5->1->2->3->NULL
//
// Explanation:
// rotate 1 steps to the right: 5->1->2->3->4->NULL
// rotate 2 steps to the right: 4->5->1->2->3->NULL
//
// Example 2:
//
// Input: 0->1->2->NULL, k = 4
// Output: 2->0->1->NULL
//
// Explanation:
// rotate 1 steps to the right: 2->0->1->NULL
// rotate 2 steps to the right: 1->2->0->NULL
// rotate 3 steps to the right: 0->1->2->NULL
// rotate 4 steps to the right: 2->0->1->NULL
//
// ***

ListNode* rotateRight(ListNode* head, int k) {
    if (!head) {
        return nullptr;
    }

    int listLen = 1;
    ListNode* curNode = head;

    // Find the length of the linked list, hook the tail element with head. Now it forms a circle.
    while (curNode->next) {
        ++listLen;
        curNode = curNode->next;
    }
    curNode->next = head;

    // Find where the new linked list should end and disconnect that node with next.
    int m = listLen - k % listLen;
    while (m--) {
        curNode = curNode->next;
    }
    ListNode* newHead = curNode->next;
    curNode->next = nullptr;

    return newHead;
}
