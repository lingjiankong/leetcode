// ***
//
// One way to serialize a binary tree is to use pre-order traversal.
// When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
// 
//      _9_
//     /   \
//    3     2
//   / \   / \
//  4   1  #  6
// / \ / \   / \
// # # # #   # #
//
// For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
//
// Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
// Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
// You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
// 
// Example 1:
// 
// Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
// Output: true
// Example 2:
// 
// Input: "1,#"
// Output: false
// Example 3:
// 
// Input: "9,#,#,1"
// Output: false
//
// ***
//
// The capacity is the number of node that can be put in the tree. The initial value is 1, which means there can be a root.
// When adding a node, capacity--;
// When adding a non-null node, it means we obtains two more leafs, then capacity +=2.
// The final capacity should be equal to 0
//
bool isValidSerialization(const string& preorder)
{
	int capacity = 1;

	istringstream in(preorder);
	
	string node;
	while (getline(in, node, ','))
	{
		capacity -= 1;
		
		if (capacity < 0)
		{
			return false;
		}

		if (node != "#")
		{
			capacity += 2;
		}
	}

	return capacity == 0;
}
