/*Question:
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
Tags: Array Hash Table
Similar Problems: 219, 220
*/

/*思路:
方法一：
用map，在插入时进行查找，如果找到就返回true；
否则，将当前元素插入map，继续循环。
方法二：
用unordered_set，获得将元素插入set后返回的迭代器，调用unordered_set的emplace函数会返回如下结果，所以只需要对返回的pair的第二个元素进行判断即可。
Returns a pair consisting of an iterator to the inserted element, or the already-existing element if no insertion happened, 
and a bool denoting whether the insertion took place. True for Insertion, False for No Insertion.
*/

//Code:
//Code 1:
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() < 2)
            return false;
        std::map<int, int> mapping;
        for (auto&& num : nums)
        {
            if (mapping.find(num) != mapping.end())
                return true;
            mapping[num] = 1;
        }
        return false;
    }
};

//Code 2:
bool containsDuplicate(std::vector<int>& nums)
{
    if (nums.empty()) return false;

    std::unordered_set<int> s;
    for (auto it = nums.cbegin(); it != nums.cend(); ++it)
    {
        auto ret = s.emplace(*it);
        if (!ret.second)
            return true;
    }
    return false;
}
