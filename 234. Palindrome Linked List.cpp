/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if(!head || !head->next)
            return true;

        // find middle element
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is now the middle element:
        // if the list is 1-2-3-4-5 the middle element is 3
        // if the list is 1-2-3-4 the middle element is 2

        // reverse second half of the linkedlist
        ListNode* head2 = slow->next; // head of second half

        ListNode* prevNode = nullptr;
        while (head2) {
            ListNode* nextNode = head2->next;
            head2->next = prevNode;
            prevNode = head2;
            head2 = nextNode;
        }
        // note here head2 is a nullptr now (because while (head2) is evaluated false)
        // therefore we return head2 = prevNode, the last element in the linkedlist
        head2 = prevNode;

        while (head && head2) {
            if (head->val != head2->val) {
                return false;
            }
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};

// class Solution:
//     def isPalindrome(self, head):
//         """
//         :type head: ListNode
//         :rtype: bool
//         """

//         def findMiddle(head):
//             """
//             if the list is 1-2-3-4-5 the middle element is 3
//             if the list is 1-2-3-4 the middle element is 2
//             """
//             slow, fast = head, head
//             while fast.next and fast.next.next:
//                 slow = slow.next
//                 fast = fast.next.next
//             return slow

//         def reverseList(head):
//             prevNode = None
//             while head:
//                 nextNode = head.next
//                 head.next = prevNode
//                 prevNode = head
//                 head = nextNode
//             return prevNode

//         if not head:
//             return True

//         middle = findMiddle(head)
//         middle.next = reverseList(middle.next)

//         p, q = head, middle.next

//         while p and q:
//             if p.val != q.val:
//                 return False
//             p, q = p.next, q.next
//         return True
