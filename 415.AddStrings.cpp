/* Question:
Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

//Code:
string addStrings(string num1, string num2) {
    std::string result;
    
    int carry = 0;
    for(int i = num1.length() - 1, j = num2.length() - 1; i >= 0 || j >= 0; --i, --j)
    {
        int a = (i >= 0)? int(num1[i] - '0') : 0;
        int b = (j >= 0)? int(num2[j] - '0') : 0;
        
        int tmp = a + b + carry;
        result = char(tmp % 10 + '0') + result;
        carry = tmp >= 10? 1 : 0;
    }
    
    if(carry == 1)
        result = '1' + result;
    return result;
}
