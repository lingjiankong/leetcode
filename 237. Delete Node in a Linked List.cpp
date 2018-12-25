// ***
//
// Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
//
// ***
// 
// Given node B:
// A -> B -> C -> D
// A -> C ------> D
void deleteNode(ListNode* node)
{
	node->val = node->next->val;
	node->next = node->next->next;
}
