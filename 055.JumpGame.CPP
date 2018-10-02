/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.
Tags: Array, Greedy
*/

/*思路:
方法一：
对于不可以到达数组尾端的情况，都存在"从当前i位置的0->前一个0或者数组首元素，都满足nums[j]+j==i的条件"
方法二：
依次遍历数组，找到可以到达的最远位置，如果在某一个元素，到达某一处的的索引位置刚好等于i且nums[i]==0，则返回false
*/

//Code:
//Code 1:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1) return true;
        if(nums[0] == 0) return false;
        
        auto iter = std::find(nums.begin(), nums.end(), 0);
        if(iter == nums.end()) return true;
        bool result = true;
        for(int i = nums.size() - 2; i > 0 && result; --i)
        {
            if(nums[i] != 0) continue;
            
            for(int j = i - 1; j >= 0; --j)
            {
                if(nums[j] + j > i)
                {
                    result = true;
                    break;
                }
                result = false;
            }
        }
        
        return result;
    }
    
//Code 2:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1) return true;
        
        int furthestIndexSofar = 0;
        for(int i = 0, iEnd = nums.size() - 1; i < iEnd; ++i)
        {
            if(nums[i] + i > furthestIndexSofar)
                furthestIndexSofar = nums[i] + i;
            if(furthestIndexSofar >= iEnd)
                return true;
            if(furthestIndexSofar == i && nums[i] == 0)
                return false;
        }
        
        return false;
    }
