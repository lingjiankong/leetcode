// This is a good question that tests how you use custom comparator in sort
// The idea here is to implement a string comparator to decide
// which string should come first during concatenation.
// Because when you have 2 numbers (let's convert them into string), you'll face only 2 cases:
//
// For example:
//
// string s1 = "9";
// string s2 = "31";
//
// case1 = s1 + s2; // 931
// case2 = s2 + s1; // 319
// Apparently, case1 is greater than case2 in terms of value.
// So, we should always put s1 in front of s2.
//
// Note on comparator: Binary function that accepts two elements in the range as arguments,
// and returns a value convertible to bool.
// The value returned indicates whether the element passed as first argument is considered
// to go before the second in the specific strict weak ordering it defines.
//
// In our case, obviously a needs to go before b if string version of a+b is greater than b+a.
string largestNumber(vector<int>& nums)
{
	sort(nums.begin(), nums.end(), [](int a, int b){ return to_string(a) + to_string(b) > to_string(b) + to_string(a); });

	string result = "";

	for (int num : nums)
	{
		result += to_string(num);
	}

	return result[0] == '0' ? "0" : result;
}
