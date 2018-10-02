/*
Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
Tags: Binary Search, Array
*/

/*思路：
方法一：
用普通的二分查找，找到target元素后，依次向左找第一次出现该元素的地方；依次向右找该元素最后一次出现的地方。
如果target出现的次数很多，该方法退化成O(n)的时间复杂度
方法二：
用两次二分查找，第一次找第一次出现的位置（在找到元素后，令end=mid-1，继续二分查找左边的元素）
同理，第二次找最后一次出现的位置（在找到元素后，令beg=mid+1，继续二分查找右边的元素）
//Code:
//Code 1:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = -1, high = -1;
        int beg = 0, end = nums.size() - 1;
        
        while(beg <= end)
        {
            int mid = beg + (end - beg) / 2;
            if(nums[mid] == target)
            {
                low = mid, high = mid;
                while(low >= beg && nums[--low] == target);
                ++low;
                while(high <= end && nums[++high] == target);
                --high;
                break;
            }
            else if(nums[mid] > target)
                end = mid - 1;
            else beg = mid + 1;
        }
        
        return {low, high};
    }
    
    //Code 2:
    std::vector<int> searchRange(std::vector<int>& nums, int target)
{
    if (nums.empty()) return {-1, -1};
    
    int rangeLow = -1;
    
    int low = 0, high = (int)nums.size()-1;
    while (low <= high)
    {
        int mid = low + (high-low)/2;
        if (nums[mid] == target)
        {
            rangeLow = mid;
            high = mid-1;
        }
        else if (nums[mid] > target)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    
    if (rangeLow == -1) return {-1, -1};
    
    int rangeHigh = rangeLow;
    low = rangeLow, high = (int)nums.size()-1;
    while (low <= high)
    {
        int mid = low + (high-low)/2;
        if (nums[mid] == target)
        {
            rangeHigh = mid;
            low = mid+1;
        }
        else if (nums[mid] > target)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    
    return {rangeLow, rangeHigh};
}
