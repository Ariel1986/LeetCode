/*Question:
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
For example,
Given nums = [0, 1, 3] return 2.
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
Tags: Array, Math, Bit manipulation
*/

/*思路:
方法一： 
利用数组元素的特殊性：数组元素是0 ~ n的，而数组下标是0 ~ n-1； 初始化一个值为n，然后与数组下标及数组值做异或操作，最后所得值即为结果。
方法二：
先求出n个数的和，然后依次减去数组中已有的值，剩余的值就是所求元素
方法三：
先将数组排序，然后二分查找第一个mid与Nums[mid]值不一样的元素
比较：如果数组已经有序，则方法三是最好的选择。其他情况下，方法一更好些
*/

//Code:
//Code 0:
    int missingNumber(vector<int>& nums) {
        if(nums.empty()) return -1;
        
        std::sort(nums.begin(), nums.end());
        
        if(nums[0] != 0) return 0;
        
        for(int i = 0, iEnd = nums.size()-1; i < iEnd; ++i)
        {
            if(nums[i] + 1 != nums[i + 1]) return nums[i] + 1;
        }
        
        return nums.size();
    }

//Code 1:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        
        for(int i = 0, iEnd = nums.size(); i < iEnd; ++i)
        {
            result ^= i;
            result ^= nums[i];
        }
            
        return result;
    }
    
 //Code 2:
      int missingNumber(vector<int>& nums) {
        int nSize = nums.size();
        int result = nSize * (nSize + 1) / 2;
        
        for(auto&& num : nums)
            result -= num;
        
        return result;
    }
    
  //Code 3:
    int missingNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        int beg = 0, end = nums.size();
        
        while(beg < end)
        {
            int mid = beg + (end - beg) / 2;
            if(nums[mid] > mid) end = mid;
            else beg = mid + 1;
        }
        
        return beg;
    }
