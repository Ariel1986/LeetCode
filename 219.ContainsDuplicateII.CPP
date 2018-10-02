/*Question:
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
Tags: Array Hash Table
Similar Problems:217, 220
*/

/*
*/

//Code:
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.empty() || k <= 0)
            return false;
        std::map<int, int> mapping;

        for (int i = 0, sz = nums.size(); i < sz; ++i)
        {
            auto iter = mapping.emplace(std::make_pair(nums[i], i));
            if (!iter.second )
            {
                if(i - mapping[nums[i]] <= k)
                    return true;
                mapping[nums[i]] = i;  //更新到最新的数字所在的位置
            }
        }
        return false;
    }
};
