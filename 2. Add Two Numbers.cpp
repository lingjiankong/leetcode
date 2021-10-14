// ***
//
// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return
// it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
// Example:
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.
//
// ***
//
// See also 415. Add Strings.

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    int carry = 0;

    while (l1 or l2 or carry) {
        int sum = 0;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        if (carry) {
            sum += 1;
        }

        current->next = new ListNode(sum % 10);
        carry = sum / 10;
        current = current->next;
    }

    return dummy.next;
}
