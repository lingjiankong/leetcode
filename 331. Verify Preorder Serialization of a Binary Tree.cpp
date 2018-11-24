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
