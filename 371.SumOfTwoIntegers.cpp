/* Question:
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
Example:
Given a = 1 and b = 2, return 3.
*/

/* Method:
借助位的运算，异或和与操作
*/

// Code:
    int getSum(int a, int b) {
        int result = 0;
        while(b != 0)
        {
            result = a ^ b;
            int carry = a & b;
            a = result;
            b = (carry << 1);
        }
        
        return result;
    }
