// ***
//
// Given two binary strings, return their sum (also a binary string).
// The input strings are both non-empty and contains only characters 1 or 0.
// 
// Example 1:
// 
// Input: a = "11", b = "1"
// Output: "100"
//
// Example 2:
// 
// Input: a = "1010", b = "1011"
// Output: "10101"
//
// ***
//
// Code is exactly same as 415. Add Strings. The only difference is changing 10 to 2.
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

        result += to_string(sum % 2);
        carry = sum / 2;
    }

    reverse(result.begin(), result.end());

    return result;
}
