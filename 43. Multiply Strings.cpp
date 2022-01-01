// ***
//
// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also
// represented as a string.
//
// Example 1:
//
// Input: num1 = "2", num2 = "3"
// Output: "6"
//
// Example 2:
//
// Input: num1 = "123", num2 = "456"
// Output: "56088"
// Note:
//
// The length of both num1 and num2 is < 110.
// Both num1 and num2 contain only digits 0-9.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.
//
// ***
//
// Just follow the rules of multiplication, pay attention to the index,
// Store the result in a vector of size num1.size() + num2.size().
// You will realize that the resulting multiplication of two integers at num[i] and num[j]
// are placed at result[i+j] and result[i+j+1]. The result is between 0 and 81.
//
//     1 2 3
//       4 5
// x________
//       1 5
//     1 0
//     5
// +________
//     1 2
//     8
//   4
// +________
// 0 5 5 3 5
//
// 0 1 2 3 4 <- Index
//         i
//         j
//       p1
//         p2
// _________
//
//       i
//         j
//     p1
//       p2
// _________
//
//     i
//         j
//   p1
//     p2
//

string multiply(string num1, string num2) {
    vector<int> resultVector(num1.size() + num2.size());

    for (int i = num1.size() - 1; i >= 0; --i) {
        for (int j = num2.size() - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');

            // Positions of where to put the resulting mul
            int p2 = i + j + 1, p1 = i + j;

            int sum = resultVector[p2] + mul;

            resultVector[p2] = sum % 10;
            resultVector[p1] += sum / 10;
        }
    }

    // Convert to string.
    string resultString;
    for (int num : resultVector) {
        resultString += to_string(num);
    }

    // Get rid of leading zeros. If the string only has one zero,
    // then it means the product is zero, and we shall return it.
    int startpos = resultString.find_first_not_of("0");

    // If we found any non-zero element, truncate all zeros and return everything from startpos.
    if (startpos != string::npos) {
        return resultString.substr(startpos);
    }

    return "0";
}
