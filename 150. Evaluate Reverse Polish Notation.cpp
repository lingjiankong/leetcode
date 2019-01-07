// ***
//
// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
// Valid operators are +, -, *, /. Each operand may be an integer or another expression.
// 
// Note:
// 
// Division between two integers should truncate toward zero.
// The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
//
// Example 1:
// Input: ["2", "1", "+", "3", "*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
//
// Example 2:
// Input: ["4", "13", "5", "/", "+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6
//
// Example 3:
// Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
// Output: 22
//
// Explanation:
//   ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
// = ((10 * (6 / (12 * -11))) + 17) + 5
// = ((10 * (6 / -132)) + 17) + 5
// = ((10 * 0) + 17) + 5
// = (0 + 17) + 5
// = 17 + 5
// = 22
//
// ***
//
// 逆波兰表达式就是把操作数放前面，把操作符后置的一种写法，我们通过观察可以发现，第一个出现的运算符，其前面必有两个数字，
// 这个运算符和之前两个数字完成运算后从原数组中删去，把得到一个新的数字插入到原来的位置，继续做相同运算，直至整个数组变为一个数字。
int evalRPN(vector<string>& tokens)
{
	unordered_map<string, function<int (int, int)> > operatorHash =
	{
		{ "+" , [] (int a, int b) { return a + b; } },
		{ "-" , [] (int a, int b) { return a - b; } },
		{ "*" , [] (int a, int b) { return a * b; } },
		{ "/" , [] (int a, int b) { return a / b; } }
	};

	stack<int> tokenStack;

	for (string token : tokens)
	{
		// If token is not an operator, push the number to stack.
		if (!operatorHash.count(token))
		{
			tokenStack.push(stoi(token));
		}
		// If token is an operator, pop last two numbers (the operands) from stack,
		// perform the operation and append the result to stack again.
		else
		{
			int left = tokenStack.top(); tokenStack.pop();
			int right = tokenStack.top(); tokenStack.pop();
			tokenStack.push(operatorHash[token](right, left));
		}
	}

	return tokenStack.top();
}
