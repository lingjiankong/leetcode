// ***
//
// Reverse a singly linked list.
//
// Example:
//
// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
//
// ***

// Iterative.
// This question is essentially asking you to reverse a linkedlist from head to nullptr.
//
// a -> b -> c -> d -> e
// a    b -> c -> d -> e
// a <- b    c -> d -> e
// a <- b <- c    d -> e
// a <- b <- c <- d    e
// a <- b <- c <- d <- e
//
// If you would like to reverse from head to node target, simply change
// "while (head != nullptr)" to "while (head != target)" (note however, linkedlist is cut in this case)
//
// For example, head = a, target = c:
// a -> b -> c -> d -> e
// a    b -> c -> d -> e
// a <- b    c -> d -> e
//
// while (head != target) {...}
// in the end, head will be c, prevNode will be b.
ListNode* reverseList(ListNode* head) {
    ListNode* prevNode = nullptr;

    while (head) {
        ListNode* nextNode = head->next;
        head->next = prevNode;
        prevNode = head;
        head = nextNode;
    }

    return prevNode;
}

// Recursive (postorder). See labuladong book pp.284 for an elegant visualization.
// By recursion's definition, what you are doing when you give "head" as input is this:
//
// head
// v
// 1 -> 2 -> 3 -> 4 -> 5-> null
//
//
// ListNode* last = reverse(head.next):
//
// head
// v
// 1 -> reverse(2 -> 3 -> 4 -> 5 -> null)
//
// head                last
// v                   v
// 1 -> 2 <- 3 <- 4 <- 5
//      |
//      v
//      null
//
//
//
// head->next->next = head:
// (2 now points to 1 instead of null)
//
// head                last
// v                   v
// 1 -> 2 <- 3 <- 4 <- 5
//   <-
//
//
//
// head->next = null:
// (1 points to null instead of 2)
//
//         head                last
//         v                   v
// null <- 1 <- 2 <- 3 <- 4 <- 5
//
//
//
//
// Finally, return last.
ListNode* reverseList(ListNode* head) {
    if (!head or !head->next) {
        return head;
    }

    ListNode* last = reverseList(head->next);

    head->next->next = head;
    head->next = nullptr;

    return last;
}
