// ***
//
// Given a string, sort it in decreasing order based on the frequency of characters.
// 
// Example 1:
// 
// Input:
// "tree"
// 
// Output:
// "eert"
// 
// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:
// 
// Input:
// "cccaaa"
// 
// Output:
// "cccaaa"
// 
// Explanation:
// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:
// 
// Input:
// "Aabb"
// 
// Output:
// "bbAa"
// 
// Explanation:
// "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.
//
// ***
//
// Exactly the same idea as 347. Top K Frequent Elements.
string frequencySort(string s)
{
	unordered_map<char, int> letterToFrequency;
	priority_queue<pair<int, int>> pq;

	for (char letter : s)
	{
		++letterToFrequency[letter];
	}

	for (auto element : letterToFrequency)
	{
		pq.push({element.second, element.first});
	}

	string toReturn;
	while (!pq.empty())
	{
		auto element = pq.top(); pq.pop();

		// string& append (size_t n, char c): Appends n consecutive copies of character c
		int frequency = element.first;
		char letter = element.second;
		toReturn.append(frequency, letter);
	}

	return toReturn;
}
