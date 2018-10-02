/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.
Tags: Array, Hash Table
*/

//Code:
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() < 2) return {};
       
        std::vector<int> numsCopy(nums);
        std::sort(numsCopy.begin(), numsCopy.end());
        
        auto binarySearch = [&numsCopy](int beg, int end, int num)->int
        {
            while(beg <= end)
            {
                int mid = beg + (end - beg) / 2;
                if(numsCopy[mid] == num)
                    return mid;
                else if(numsCopy[mid] > num)
                    end = mid - 1;
                else beg = mid + 1;
            }
            return -1;
        };
       
        for(int i = 0, iEnd = numsCopy.size() - 1; i < iEnd; ++i)
        {
            int index = binarySearch(i+1, numsCopy.size() - 1, target - numsCopy[i]);
            if(index != -1)
            {
                auto iter1 = std::find(nums.begin(), nums.end(), numsCopy[i]);
                auto iter2 = std::find(nums.begin(), nums.end(), numsCopy[index]);
                if(numsCopy[i] == numsCopy[index])
                        iter2 = std::find(iter1+1, nums.end(), numsCopy[index]);
                return std::vector<int>{iter1 - nums.begin(), iter2 - nums.begin()};
            }
        }
        
        return {};
    }
};
