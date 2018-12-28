// ***
//
// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
// 
// Note:
// 
// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.
//
// ***
//
// See also 2. Add Two Numbers.
string addStrings(string num1, string num2)
{
	int i = num1.size() - 1;
	int j = num2.size() - 1;
	int carry = 0;

	string result = "";

	while (i >= 0 || j >= 0 || carry)
	{
		int sum = 0;
		
		if (i >= 0)
		{
			sum += num1[i--] - '0';
		}

		if (j >= 0)
		{
			sum += num2[j--] - '0';
		}

		if (carry)
		{
			sum += 1;
		}

		result += to_string(sum % 10);
		carry = sum / 10;
	}

	reverse(result.begin(), result.end());

	return result;
}
