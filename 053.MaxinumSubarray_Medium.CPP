/* Question:
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

/* 思路：
依次处理array中的每一个元素，如果当前的和大于零，curSum+=nums[i]; 
否则，curSum=nums[i]（不需要单独处理array中元素全为负的情况）
result=max（result，curSum）
*/

// Code:
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int curSum = nums[0];
        int result = curSum;
        for(std::vector<int>::size_type i = 1; i < nums.size(); ++i)
        {
            if(curSum > 0) curSum += nums[i];
            else curSum = nums[i];
            result = std::max(result, curSum);
        }
        
        return result;
    }
};

// Good, 典型的贪心算法
// following is my answer.
   int maxSubArray(vector<int>& nums) {
        int maxendinghere = nums[0], maxsofar = nums[0]; // because nums containing at least one number
        for (vector<int>::const_iterator it = nums.cbegin()+1; it != nums.cend(); ++it)
        {
            maxendinghere = std::max(maxendinghere+*it, *it);
            maxsofar = std::max(maxsofar, maxendinghere);
        }
        return maxsofar;
    }
