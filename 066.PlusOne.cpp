/*Question:
Given a non-negative number represented as an array of digits, plus one to the number.
The digits are stored such that the most significant digit is at the head of the list.
Subscribe to see which companies asked this question
Tag: Array, Math
*/

/*思路：
进位一直加到前面的元素，不要忘记最后一位的进位
*/

//Code:
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.empty()) return {0};
        
        vector<int> plusOneResult;
        int carry = 1;

        for(auto iter = digits.rbegin(); iter < digits.rend(); ++iter)
        {
            int temp = *iter + carry;
            plusOneResult.insert(plusOneResult.begin(), temp % 10);
            carry = temp / 10;
        }
        
        if(carry > 0) 
            plusOneResult.insert(plusOneResult.begin(), carry);
        
        return plusOneResult;
    }
};
