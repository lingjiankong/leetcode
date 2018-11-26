// ***
//
// The set [1,2,3,...,n] contains a total of n! unique permutations.
// 
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
// 
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
//
// Given n and k, return the kth permutation sequence.
// 
// Note:
// 
// Given n will be between 1 and 9 inclusive.
// Given k will be between 1 and n! inclusive.
//
// Example 1:
// 
// Input: n = 3, k = 3
// Output: "213"
//
// Example 2:
// 
// Input: n = 4, k = 9
// Output: "2314"
//
// ***
//
// This question was confusing to me, due to my bad math intuition on permutation.
//
// say n = 4, you have {1, 2, 3, 4}
//
// If you were to list out all the permutations you have
// 
// 1 + (permutations of 2, 3, 4)
// 2 + (permutations of 1, 3, 4)
// 3 + (permutations of 1, 2, 4)
// 4 + (permutations of 1, 2, 3)
//
// There are total of 4! = 24 possibilities.
// To select the first number, your have 4 chunks, each number (1,2,3,4) can occur 3! = 6 times,
//
// For example n = {1,2,3,4}, k = 17,
// The next number is nums[16 / 3!] = nums[2] = 3
// The new k is 16 % 3! = 4
// Result is 3___
//
// Now, n = {1,2,4}, k = 4,
// The next number is nums[4 / 2!] = nums[2] = 4
// The new k is 4 % 2! = 0
// Result is 34__
//
// Now, n = {1,2}, k = 0
// The next number is nums[0 / 0!] = nums[0] = 1
// The new k is 0 % 0! = 0
// Result is 341_
//
// Now, n = {2}, k = 0
// The next number is nums[0 / 0!] = nums[0] = 2
// The new k is 0 % 0! = 0 (for loop ends here)
// Result is 3412.
//
string getPermutation(int n, int k)
{
	string toReturn;

	// Remaining numbers available for permutation.
	// Initially it is every number from 0 to 9.
	string nums = "123456789";

	vector<int> factorial(n, 1);
	for (int i = 1; i < n; ++i)
	{
		factorial[i] = factorial[i - 1] * i;
	}

	// --k so we can deal with 0 based indexing.
	--k;

	for (int i = n; i >= 1; --i)
	{
		// Calculate the "chunk" the first number belongs to
		int j = k / factorial[i - 1];
		toReturn.push_back(nums[j]);

		// Get rid of this number just been added. We no longer need this number
		// in remaining permutation.
		nums.erase(j, 1);

		// Calcualte the new k for remaining permutations.
		k %= factorial[i - 1];
	}

	return toReturn;
}
