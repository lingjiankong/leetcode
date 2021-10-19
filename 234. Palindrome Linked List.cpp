// ***
//
// Given a singly linked list, determine if it is a palindrome.
//
// Example 1:
//
// Input: 1->2
// Output: false
//
// Example 2:
//
// Input: 1->2->2->1
// Output: true
//
// ***

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head or !head->next) {
            return true;
        }

        // Find middle element
        // slow is now the middle element:
        //
        // If the while condition is while (fast && fast->next)
        // If the list is 1-2-3-4-5 the middle element is 3
        // If the list is 1-2-3-4 the middle element is 3
        // i.e. the mid element will be on the right part if even number of elements.
        //
        // If the while condition is while (fast->next && fast->next->next):
        // If the list is 1-2-3-4-5 the middle element is 3
        // If the list is 1-2-3-4 the middle element is 2
        // i.e. the mid element will be on the left part if even number of elements.
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half of the linkedlist
        // slow is now the head of second half
        ListNode* head2 = reverse(slow);

        while (head and head2) {
            if (head->val != head2->val) {
                return false;
            }

            head = head->next;
            head2 = head2->next;
        }

        return true;
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode* prevNode = nullptr;

        while (head) {
            ListNode* nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }

        // Note here head is a nullptr now (because while (head) is evaluated false)
        // Therefore current prevNode (the last element in the linkedlist) is the new head.
        return prevNode;
    }
};

// Without modifying linkedlist. Using the property of postorder traversal.
// When you are postorder traversing a linked list, you are printing from tail to head.
// Keep left fixed, postorder traverse right and use two pointers.
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        _left = head;
        postorder(head);
        return _ans;
    }

private:
    void postorder(ListNode* right) {
        if (not right) {
            return;
        }

        postorder(right->next);

        if (_left->val != right->val) {
            _ans = false;
        }
        
        _left = _left->next;
    }

    ListNode* _left;
    bool _ans = true;
};
