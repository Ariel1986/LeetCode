/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.
For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
Tags: Array Dynamic Programming
*/

/*思路：
考虑负数的情况，所以需要保存最大值与最小值
*/

//Code:
//Code 1:
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int result = nums[0];
        int preMin = nums[0];
        int preMax = nums[0];
        
        for(int i = 1, iEnd = nums.size(); i < iEnd; ++i)
        {
            if(nums[i] > 0)
            {
                preMin = std::min(preMin * nums[i], nums[i]);
                preMax = std::max(preMax * nums[i], nums[i]);
            }
            else
            {
                int curMin = std::min(preMax * nums[i], nums[i]);
                int curMax = std::max(preMin * nums[i], nums[i]);
                preMin = curMin;
                preMax = curMax;
            }
            
            result = std::max(result, preMax);
        }
        
        return result;
    }
};

Code 2:
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int result = nums[0];
        int preMin = nums[0];
        int preMax = nums[0];
        
        for(int i = 1, iEnd = nums.size(); i < iEnd; ++i)
        {
                int a = preMin * nums[i];
                int b = preMax * nums[i];
                
                preMin = std::min(std::min(a, b), nums[i]);
                preMax = std::max(std::max(a, b), nums[i]);
            
            result = std::max(result, preMax);
        }
        
        return result;
    }
};
