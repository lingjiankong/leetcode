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
        if (!head or !head->next) {
            return head;
        }

        ListNode* mid = findMiddle(head);
        ListNode* rightHead = mid->next;
        mid->next = nullptr;

        return mergeTwoSortedLists(sortList(head), sortList(rightHead));
    }

private:
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Need to use while (fast->next and fast->next->next)
        // because we need to get rightHead and set mid->next = nullptr.
        while (fast->next and fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
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
};

// See also 147. Insertion Sort List for insertion sort.
