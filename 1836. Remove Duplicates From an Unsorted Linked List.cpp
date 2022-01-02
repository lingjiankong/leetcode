// ***
//
// Given the head of a linked list, find all the values that appear more than once in the list and delete the nodes that
// have any of those values.
//
// Return the linked list after the deletions.
//
// Example 1:
//
//
// Input: head = [1,2,3,2]
// Output: [1,3]
// Explanation: 2 appears twice in the linked list, so all 2's should be deleted. After deleting all 2's, we are left
// with [1,3].
//
// ***

// Same idea as 203. Remove Linked List Elements.
class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        // Find duplciates
        ListNode* curNode = head;
        while (curNode) {
            ++val2freq[curNode->val];
            curNode = curNode->next;
        }

        // Delete duplicates
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevNode = &dummy;
        while (prevNode->next) {
            if (val2freq[prevNode->next->val] > 1) {
                ListNode* toBeDeleted = prevNode->next;
                prevNode->next = prevNode->next->next;  // prevNode itself is anchored. Update its next ptr only
                delete toBeDeleted;
            } else {
                prevNode = prevNode->next;  // advance prevNode
            }
        }

        return dummy.next;
    }

private:
    unordered_map<int, int> val2freq;
};
