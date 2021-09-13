// ***
//
// Sort a linked list in O(n log n) time using constant space complexity.
//
// Example 1:
//
// Input: 4->2->1->3
// Output: 1->2->3->4
//
// Example 2:
//
// Input: -1->5->3->4->0
// Output: -1->0->3->4->5
//
// ***

// Merge sort
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* mid = findMiddle(head);
        ListNode* rightHead = mid->next;
        mid->next = nullptr;

        return mergeTwoLists(sortList(head), sortList(rightHead));
    }

private:
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* current = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }

            current = current->next;
        }

        current->next = l1 ? l1 : l2;

        return dummy.next;
    }
};

// See also 147. Insertion Sort List for insertion sort.
