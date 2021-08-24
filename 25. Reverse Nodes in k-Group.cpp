// ***
//
// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a
// multiple of k then left-out nodes, in the end, should remain as it is.
//
// You may not alter the values in the list's nodes, only nodes themselves may be changed.
//
// Example 1:
//
// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
//
// Example 2:
// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]
// Example 3:
//
// Input: head = [1,2,3,4,5], k = 1
// Output: [1,2,3,4,5]
// Example 4:
//
// Input: head = [1], k = 1
// Output: [1]
//
// ***

// Recursive see also. 206. Reverse Linked List.
//
//               _________________________
//      newHead  |                       |
//           v   |                       v
// 1 <- 2 <- 3   4 <- 5 <- 6   7 <- 8 <- 9    10 -> 11
// |                       ^   |              ^
// |                       |   |              |
// -------------------------   ----------------
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (not head) {
            return nullptr;
        }

        // Reverse K elements between [a, b) (the element before b will be the new head).
        ListNode *a = head, *b = head;

        for (int i = 0; i < k; ++i) {
            // No enough elements to reverse. Simply return the original head.
            if (not b) {
                return head;;
            }
            b = b->next;
        }

        // Otherwise, reverse [a, b) and return the new head.
        ListNode* newHead = reverse(a, b);

        // Recursively reverse b and beyond.
        a->next = reverseKGroup(b, k);

        return newHead;
    }

private:
    // reverse a -> x -> y -> z -> b to z -> ... -> a and return new head (z).
    // Note, b is NOT the new head! (Think about the case when b is a nullptr i.e. 206 Reverse Linked List)
    ListNode* reverse(ListNode* a, ListNode* b) {
        ListNode* prevNode = nullptr;

        while (a != b) {
            ListNode* nextNode = a->next;
            a->next = prevNode;
            prevNode = a;
            a = nextNode;
        }

        return prevNode;
    }
};

