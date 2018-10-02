/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.
For example, given array S = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
Tags: Array, Two Pointers
*/

/*思路：
由于循环的次数比较多，很容易产生超时错误，所以一定要对一些特殊情况进行处理，尤其题目中提示
Note: The solution set must not contain duplicate triplets.
*/

//Code:
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3)
            return {};
            
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        int sz = nums.size();
        
        auto findNum = [&nums](int beg, int end, int num)->int
        {
            while(beg <= end)
            {
                int mid = beg + (end - beg) / 2;
                if(nums[mid] == num)
                    return mid;
                else if(nums[mid] > num)
                    end = mid - 1;
                else beg = mid + 1;
            }
            
            return -1;
        };
        
        for(int i = 0, iEnd = sz - 2; i < iEnd; ++i)
        {
            if(nums[i] > 0) break;   //加判断，减少循环次数
            if(i > 0 && nums[i] == nums[i-1]) continue;  //加判断，减少循环次数
            
            for(int j = i + 1, jEnd = sz - 1; j < jEnd; ++j)
            {
                if(j != i + 1 && nums[j] == nums[j-1]) continue;  //加判断，减少循环次数
                int index = findNum(j + 1, jEnd, 0 - nums[i] - nums[j]);
                if(index != -1)
                    result.emplace_back(std::vector<int>{nums[i],nums[j],nums[index]});
            }
        }
        return result;
    }
};
