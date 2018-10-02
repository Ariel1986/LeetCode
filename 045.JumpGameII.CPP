/*Question:
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
For example:
Given array A = [2,3,1,1,4]
The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
Note:
You can assume that you can always reach the last index.
Tags: Array Greedy
*/

/*思路：
先令setps=0
对于数组中的每个元素nums[i]，如果nums[i]+i>=nums.size()-1,则说明从当前位置即可走到末尾，返回++steps
否则，则找到(i+1, nums[i]+i)中可以走的最大步数，并令i为当前位置，++steps；然后继续循环
*/

//Code:
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1)return 0;
        
        int pos = 0;
        int steps = 0;
        int sz = nums.size();
        
        while(pos < sz)
        {
            int maxVal = nums[pos] + pos;
            if(maxVal >= sz-1)
                return ++steps;
                
            int newPos = pos+1;
            for(int j = pos+1; j <= pos+nums[pos]; ++j)
            {
                int temp = nums[j] + j;
                if(temp > maxVal)
                {
                    maxVal = temp;
                    newPos = j;
                }
            }
            
            ++steps;
            pos = newPos;
        }
        
        return 0;
    }
};
