// ***
//
// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes
// first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//
//
// Example 1:
//
//
// Input: l1 = [7,2,4,3], l2 = [5,6,4]
// 7243 + 564 = 7807
// Output: [7,8,0,7]
// Example 2:
//
// Input: l1 = [2,4,3], l2 = [5,6,4]
// 243 + 564 = 807
// Output: [8,0,7]
// Example 3:
//
// Input: l1 = [0], l2 = [0]
// 0 + 0 = 0
// Output: [0]
//
// ***

// Use stack to simulate reversing the linked list.
// Compare the 2. Add Two Numbers, the returned linked list are different
// (most significant digit as linked list head in this question vs.
// least significant digit as linked list head in 2. Add Two Numbers)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* head = nullptr;
        int carry = 0;

        while (!s1.empty() or !s2.empty() or carry) {
            int sum = 0;

            if (not s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            if (not s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            if (carry) {
                sum += 1;
            }

            carry = sum / 10;
            ListNode* current = new ListNode(sum % 10);

            // Construct linked list from tail node to head node, moving from right to left.
            current->next = head;
            head = current;
        }

        return head;
    }
};
