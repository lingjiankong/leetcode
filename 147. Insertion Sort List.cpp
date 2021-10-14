// ***
//
// Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.
//
// The steps of the insertion sort algorithm:
//
// Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
// At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the
// sorted list and inserts it there. It repeats until no input elements remain. The following is a graphical example of
// the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the
// list. One element (red) is removed from the input data and inserted in-place into the sorted list with each
// iteration.
//
//
// Example 1:
//
// Input: head = [4,2,1,3]
// Output: [1,2,3,4]
//
//
// Example 2:
//
// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]
//
// ***

// Very easy once you are able to visualize it and and walk it through.
// We check if cur->next is at the correct position.
// If not, we traverse the linked list from left to right to insert it to the corret position.
//
//
//           misplaced
//           v
// d 1 2 3 5 4 6 7
// ^       ^
// prev    cur
//
// See https://www.youtube.com/watch?v=N1VVLLan6S0
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (not head or not head->next) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode* cur = head;
        ListNode* prev = nullptr;  // use the traverse from left to right to find the insertion position.

        // find if cur->next is at correct position.
        while (cur and cur->next) {
            if (cur->val <= cur->next->val) {
                cur = cur->next;  // cur->next is at the correct position, keep traversing.
            } else { // cur->next is misplaced.
                ListNode* misplaced = cur->next;
                cur->next = cur->next->next;

                prev = &dummy;  // traverse from left to right to find the correct insertion position.
                while (prev->next->val <= misplaced->val) {
                    prev = prev->next;
                }

                // Now we've found where to insert the misplaced element. For the above example, prev is now at 3
                // insert misplaced element right after prev.
                misplaced->next = prev->next;
                prev->next = misplaced;
            }
        }

        return dummy.next;
    }
};
