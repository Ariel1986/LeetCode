/* Question:
Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/* Method:
利用相同的两个数异或得0的性质
*/

// Code:
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(auto&& num : nums)
        {
            result ^= num;
        }
        
        return result;
    }
};
