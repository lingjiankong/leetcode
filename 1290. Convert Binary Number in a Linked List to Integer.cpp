// ***
//
// Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0
// or 1. The linked list holds the binary representation of a number.
//
// Return the decimal value of the number in the linked list.
//
// Example:
//
// Input: head = [1,0,0]
// Output: 4
//
// ***

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num = 0;
        while (head) {
            num = num * 2 + head->val;
            head = head->next;
        }
        return num;
    }
};
