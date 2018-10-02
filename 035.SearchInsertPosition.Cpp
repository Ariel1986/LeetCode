/* Question:
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.
Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
Tags: Array, Binary search
*/

/*思路：
思路一： 从头到尾顺序比较元素
思路二： 用二分查找比较元素,可以在代码实现的过程中用lambda表达式实现二分查找的功能。
*/

//Code：
//思路一代码：
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        std::vector<int>::size_type sz = nums.size();
        if(sz < 1) return -1;
        int i = 0;
        
        while(i < sz)
        {
            if(nums[i] < target) ++i;
            else return i;
        }
        
        return (i == sz)? i : -1;
    }
};

//思路二代码：
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        
        auto binarySearch = [&nums, target]()->int
        {
            int low = 0, high = nums.size() - 1;
            while(low <= high)
            {
                int mid = low + (high - low) / 2;
                if(nums[mid] == target) 
                    return mid;
                else if(nums[mid] < target) 
                    low = mid + 1;
                else if(nums[mid] > target) 
                    high = mid - 1;
            }
            return low;
        };
        return binarySearch();
    }
};
