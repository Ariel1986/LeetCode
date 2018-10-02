/*
Given an array of integers, every element appears three times except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
Tags: Bit Manipulation
*/

/* Method:
此处很巧妙的先对数组排序，把相同的元素放在相邻的位置。
也可以建立map统计每个元素出现的次数，但是这样空间复杂度变成o(n)。
*/

//Code:
//Code 1:
    int singleNumber(vector<int>& nums) {
        std::map<int, int> m;
        for(auto&& num : nums)
        {
            if(m.find(num) != m.end())
                ++m[num];
            else 
                m[num] = 1;
        }
        
        auto iter = std::find_if(m.begin(), m.end(),
                                [&](const std::pair<int, int>& p)
                                    {return p.second != 3;});

        return iter->first;
    }

//Code 2:
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int i = 0, iEnd = nums.size();
        while(i + 3 < iEnd)
        {
            if(nums[i] != nums[i + 2])
            {
                return nums[i];
            }
            else 
            {
                i += 3;
            }
        }
        return nums[i];
    }
};

// Solution 2: count the number of bits
int singleNumber(std::vector<int>& nums)
{
    int count[32] = {0};
    int result = 0;
    for (int i = 0; i < 32; ++i)
    {
        for (auto&& num : nums)
        {
            if ((num>>i) & 1)
                count[i]++;
        }
        result |= (count[i]%3) << i;
    }
    return result;
}

// Solution 3: use bit manip
int singleNumber(std::vector<int>& nums)
{
    int ones = 0, twos = 0, threes = 0;
    for (auto&& num : nums)
    {
        twos |= ones & num;   // bit occurs twice
        ones ^= num;          // bit occurs once
        threes = ones & twos; // bit occurs three times
        
         // clear the bit which occurs three times
        ones &= ~threes;
        twos &= ~threes; 
    }
    return ones;
}
