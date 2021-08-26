// ***
//
// Given a sorted linked list, delete all duplicates such that each element appear only once.
//
// Example 1:
//
// Input: 1->1->2
// Output: 1->2
//
// Example 2:
//
// Input: 1->1->2->3->3
// Output: 1->2->3
//
// ***

// Does not delete the duplicated node
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (not head) {
            return nullptr;
        }

        ListNode *slow = head, *fast = head->next;
        while (fast) {
            if (slow->val != fast->val) {
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }

        slow->next = nullptr;

        return head;
    }
};

// Delete the duplicated node.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy = ListNode(0);
        dummy.next = head;

        ListNode* prevNode = &dummy;

        while (prevNode->next) {
            if (prevNode != &dummy && prevNode->next->val == prevNode->val) {
                ListNode* toBeDeleted = prevNode->next;
                prevNode->next = prevNode->next->next;
                delete toBeDeleted;
            } else {
                prevNode = prevNode->next;
            }
        }

        return dummy.next;
    }
};

