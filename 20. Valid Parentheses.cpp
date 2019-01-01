// ***
//
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// 
// An input string is valid if:
// 
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.
// 
// Example 1:
// Input: "()"
// Output: true
// 
// Example 2:
// Input: "()[]{}"
// Output: true
// 
// Example 3:
// Input: "(]"
// Output: false
// 
// Example 4:
// Input: "([)]"
// Output: false
// 
// Example 5:
// Input: "{[]}"
// Output: true
//
// ***
bool isValid(string s)
{
	stack<char> seen;

	for (char c : s)
	{
		if (c == '{' || c == '[' || c == '(')
		{
			seen.push(c);
		}
		else
		{
			if (seen.empty())
			{
				return false;
			}
			else if (c == '}' && seen.top() != '{')
			{
				return false;
			}
			else if (c == ']' && seen.top() != '[')
			{
				return false;
			}
			else if (c == ')' && seen.top() != '(')
			{
				return false;
			}
			else
			{
				seen.pop();
			}
		}
	}

	return seen.empty();
}
