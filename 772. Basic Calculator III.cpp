// ***
//
// Implement a basic calculator to evaluate a simple expression string.
// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
// The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . The integer division should truncate toward zero.
// You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].
// 
// Some examples:
// "1 + 1" = 2
// " 6-4 / 2 " = 4
// "2*(5+5*2)/3+(6/2+8)" = 21
// "(2+6* 3+5- (3*14/7+2)*5)+3"=-12
// 
// Note: Do not use the eval built-in library function.
//
// ***
//
// Just memorize the solution. See comments.
int calculate(string s)
{
	int n = s.size(), num = 0, curRes = 0, finalRes = 0;

	// Initialize the dummy operator as "+"
	char op = '+';

	for (int i = 0; i < n; ++i)
	{
		char c = s[i];
		if (isdigit(c))
		{
			num = num * 10 + (c - '0');
		}
		else if (c == '(')
		{
			int j = i, count = 0;
			for (; i < n; ++i)
			{
				if (s[i] == '(')
				{
					++count;
				}
				if (s[i] == ')')
				{
					--count;
				}
				if (count == 0)
				{
					break;
				}
			}
			// Recusively deal with calculations inside parenthesis.
			// j is the index of '(' and i is now the index of ')'.
			// Everything inside parenthesis is now num.
			num = calculate(s.substr(j + 1, i - j - 1));
		}
		// Here 'c' is the *current* operator at s[i], 'op' is the *last* operator you've seen.
		// i.e. The relationship is (curRes) (op) (num) (c)
		// This is basically saying that if you see a new operator, this new operator act like a break point,
		// and you should perform the operation specified by the last seen operator.
		// So you can do calculation curRes = curRes op num
		// if c is + or - then you can safely add curRes to the finalRes.
		if (c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1)
		{
			switch (op)
			{
				case '+': curRes += num; break;
				case '-': curRes -= num; break;
				case '*': curRes *= num; break;
				case '/': curRes /= num; break;
			}
			// If c = '+' or '-' (but not '*' or '/'), then we can safely add all curRes to final Res, and reset curRes.
			// because '+' and '-' have the lowest priority in arithmatic calculation.
			if (c == '+' || c == '-' || i == n - 1)
			{
				finalRes += curRes;
				curRes = 0;
			}

			op = c;
			num = 0;
		}
	}

	return finalRes;
}
