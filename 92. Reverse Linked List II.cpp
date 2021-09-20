// ***
//
// Reverse a linked list from position m to n. Do it in one-pass.
//
// Note: 1 ≤ m ≤ n ≤ length of list.
//
// Example:
//
// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL
//
// ***

// Iterative.
//
// You want to form something like the following (m = 2, n = 5)
//
//      ______
//      |    |
//      |    v
// 1    2    3 -> 4 -> 5 -> 6 -> 7
// |    ^
// |____|
//
// ^    ^    ^
// prev      next
//      current
//
//
//
// curNode->next = nextNode->next;
//      ___________
//      |         |
//      |         v
// 1    2    3 -> 4 -> 5 -> 6 -> 7
// |    ^
// |____|
//
// ^    ^    ^
// prev      next
//      current
//
//
//
// nextNode->next = prevNode->next;
//      ___________
//      |         |
//      |         v
// 1    2 <- 3    4 -> 5 -> 6 -> 7
// |    ^
// |____|
//
// ^    ^    ^
// prev      next
//      current
//
//
//
// prevNode->next = nextNode;
//      ___________
//      |         |
//      |         v
// 1    2 <- 3    4 -> 5 -> 6 -> 7
// |         ^
// |_________|
//
// ^    ^    ^
// prev      next
//      current
//
//
// nextNode = curNode->next;
//      ___________
//      |         |
//      |         v
// 1    2 <- 3    4 -> 5 -> 6 -> 7
// |         ^
// |_________|
//
// ^    ^         ^
// prev current   next
//
//
// ...
//      ________________
//      |              |
//      |              v
// 1    2 <- 3 <- 4    5 -> 6 -> 7
// |              ^
// |______________|
//
// ^    ^              ^
// prev current        next
//
// ...
//
//      _____________________
//      |                   |
//      |                   v
// 1    2 <- 3 <- 4 <- 5    6 -> 7
// |                   ^
// |___________________|
//
// ^    ^                   ^
// prev current             next
//
// prev and current do not change, only next changes.
//
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) {
            return nullptr;
        }

        ListNode dummy = ListNode(0);
        dummy.next = head;

        ListNode* prevNode = &dummy;

        for (int i = 1; i < m; ++i) {
            prevNode = prevNode->next;
        }

        ListNode* curNode = prevNode->next;

        int numOps = n - m;
        while (numOps--) {
            ListNode* nextNode = curNode->next;
            curNode->next = nextNode->next;
            nextNode->next = prevNode->next;
            prevNode->next = nextNode;
        }

        return dummy.next;
    }
};

// Recursive. Harder to understand. Compare with recursive solution for 206. Reverse Linked List.
// See labuladong book pp. 286.
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == 1) {
            return reverseFirstN(head, n);
        }

        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;
    }

private:
    // Reverse the first n nodes. Note that the last node of the reversed node needs to point to _successor
    // For exmaple, n = 4
    //
    //
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null
    //
    // head
    // v
    // 1 -> reverseFirstN-1(2 -> 3 -> 4 -> 5 -> 6 -> null) ()
    //
    //      ________________
    // head |              |
    // v    |              v
    // 1 -> 2 <- 3 <- 4 <- 5 -> 6 -> null
    //
    // _____________________
    // |                   |
    // |                   v
    // 1 <- 2 <- 3 <- 4 <- 5 -> 6 -> null
    //
    ListNode* reverseFirstN(ListNode* head, int n) {
        if (n == 1) {
            _successor = head->next;
            return head;
        }

        ListNode* last = reverseFirstN(head->next, n - 1);

        head->next->next = head;
        head->next = _successor;

        return last;
    }

    ListNode* _successor = nullptr;
};
