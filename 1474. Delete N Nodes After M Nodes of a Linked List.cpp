// ***
//
// Given the head of a linked list and two integers m and n. Traverse the linked list and remove some nodes in the
// following way:
//
// Start with the head as the current node.
// Keep the first m nodes starting with the current node.
// Remove the next n nodes
// Keep repeating steps 2 and 3 until you reach the end of the list.
// Return the head of the modified list after removing the mentioned nodes.
//
// Example 1:
//
// Given the head of a linked list and two integers m and n. Traverse the linked list and remove some nodes in the
// following way:
//
// Start with the head as the current node.
// Keep the first m nodes starting with the current node.
// Remove the next n nodes
// Keep repeating steps 2 and 3 until you reach the end of the list.
// Return the head of the modified list after removing the mentioned nodes.
//
// Example 2:
//
// Input: head = [1,2,3,4,5,6,7,8,9,10,11], m = 1, n = 3
// Output: [1,5,9]
// Explanation: Head of linked list after removing nodes is returned.
//
// Example 3:
//
// Input: head = [1,2,3,4,5,6,7,8,9,10,11], m = 3, n = 1
// Output: [1,2,3,5,6,7,9,10,11]
//
// Example 4:
//
// Input: head = [9,3,7,7,9,10,8,2], m = 1, n = 2
// Output: [9,7,8]
//
// Constraints:
//
// The given linked list will contain between 1 and 10^4 nodes.
// The value of each node in the linked list will be in the range [1, 10^6].
// 1 <= m,n <= 1000
//
// ***

// See also 19. Remove Nth Node from End of List.
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode *slow = head, *fast = head;

        while (fast) {
            int mTemp = m;
            int nTemp = n;

            while (fast and mTemp-- > 0) {
                // 1-based indexing: slow points to the m th element, fast points to the m + n + 1 th element
                // 0-based indexing: slow points to the m - 1 th element, fast points to the m + n th element
                // that's why we update slow 1 step "slower" here.
                slow = fast;
                fast = fast->next;
            }

            while (fast and nTemp-- > 0) {
                fast = fast->next;
            }

            // Remove all elements between slow and fast.
            slow->next = fast;
        }

        return head;
    }
};
