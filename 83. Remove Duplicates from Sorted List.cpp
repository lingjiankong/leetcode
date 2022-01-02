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

// Without using dummy node (since we will never delete the first element).
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curNode = head;  // Need to keep head as is because you need to return it in the end;

        while (curNode and curNode->next) {
            if (curNode->next->val == curNode->val) {
                ListNode* toBeDeleted = curNode->next;
                curNode->next = curNode->next->next;  // anchor curNode, update its next ptr only
                delete toBeDeleted;
            } else {
                curNode = curNode->next;  // advance curNode itself.
            }
        }

        return head;
    }
};

// Using dummy node. Similar to 203. Remove Linked List Elements
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevNode = &dummy;

        while (prevNode->next) {
            if (prevNode != &dummy and prevNode->val == prevNode->next->val) {
                ListNode* toBeDeleted = prevNode->next;
                prevNode->next = prevNode->next->next;  // anchor prevNode, update its next ptr only
                delete toBeDeleted;
            } else {
                prevNode = prevNode->next;  // advance prevNode itself.
            }
        }

        return dummy.next;
    }
};

