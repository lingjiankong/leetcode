// ***
//
// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the
// original list.
//
// Example 1:
//
// Input: 1->2->3->3->4->4->5
// Output: 1->2->5
//
// Example 2:
// Input: 1->1->1->2->3
// Output: 2->3
//
// ***

// You may also use method same as 1836. Remove Duplicates From an Unsorted Linked List.
// Much easier to remember.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head or !head->next) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevNode = &dummy;

        while (head) {
            if (head->next and head->val == head->next->val) {
                while (head->next and head->val == head->next->val) {
                    ListNode* toBeDeleted = head;
                    head = head->next;
                    delete toBeDeleted;
                }
                prevNode->next = head->next;  // skip all duplicated node.
            } else {
                prevNode = prevNode->next;
            }

            head = head->next;  // move forward.
        }

        return dummy.next;
    }
};
