// ***
//
// Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.
// You may assume the integer do not contain any leading zero, except the number 0 itself.
// The digits are stored such that the most significant digit is at the head of the list.
//
// Example :
//
// Input: [1,2,3]
// Output: [1,2,4]
//
// ***
//
// Note that the question specifies that the most significant digit is at the head of the list.
//
// This question can be done recursively, node by node.
// First, deal with the tail element first, +1 and see if we have carry, change the node value and returns carry.
// If there's still carry left after the entire dfs is finished, we simply add a new 1 to the front.
//
// See also 66. Plus One. Same idea.

class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        int finalCarry = _dfs(head);

        if (finalCarry == 1) {
            ListNode* newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }

        return head;
    }

private:
    // Returns carry to parent node.
    int _dfs(ListNode* node) {

        // Returns carry 1 to right most tail node.
        if (!node) {
            return 1;
        }

        // Get carry as you are going from right to left.
        int carry = _dfs(node->next);
        int sum = node->val + carry;
        node->val = sum % 10;

        return sum / 10;
    }
};
