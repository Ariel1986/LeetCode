/*
Given an array of n integers where n > 1, nums, 
return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
Solve it without division and in O(n).
For example, given [1,2,3,4], return [24,12,8,6].
Follow up:
Could you solve it with constant space complexity? 
(Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

//Code:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> result(nums.size());
        
        int curProduct = 1;
        for(int i = 0, iEnd = nums.size(); i < iEnd; ++i)
        {
            result[i] = curProduct;
            curProduct *= nums[i];
        }
        
        curProduct = 1;
        for(int i = nums.size() - 1; i >= 0; --i)
        {
            result[i] *= curProduct;
            curProduct *= nums[i];
        }
        
        return result;
    }
