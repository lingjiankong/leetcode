// ***
//
// Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
//
// ***
//
// Given node B:
// A -> B -> C -> D
// A -> C ------> D

// Delete next node and pretend the node to be deleted will be the next node.
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (not node->next) {
            node = nullptr;
        }

        ListNode* nextNode = node->next;
        node->next = nextNode->next;
        node->val = nextNode->val;
        delete nextNode;
    }
};
