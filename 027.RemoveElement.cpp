/*Question:
Given an array and a value, remove all instances of that value in place and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.
Example:
Given input array nums = [3,2,2,3], val = 3
Your function should return length = 2, with the first two elements of nums being 2.
Hint: Try two pointers.
Tag: Array, Two Pointers
*/

/*思路：
方法一：设置两个指针处理数组，T(n)=O(n);
方法二：
1）由于sort方法是O(log(n))的，所以可以借助该方法对数组排序，但是判断条件是是否等于指定元素，
2）然后在排序数组中查找该元素，如果找到则返回该元素第一次出现的位置；如果没找到该元素，则返回数组最后一个元素的位置
3）用find的结果减去数组收元素的位置即为排序后数组的长度
*/

//Code:
//思路一：
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        
        auto sz = nums.size();
        int preIndex = 0;
        
        for(int curIndex = 0; curIndex < sz; ++curIndex)
        {
            if(nums[curIndex] != val)
                    nums[preIndex++] = nums[curIndex];
        }
        return preIndex;
    }
};

//思路二：
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return false;
        
        std::sort(nums.begin(), nums.end(), [val](const int& a,const int& b){ return a!=val && b==val;});
        auto iter = find(nums.begin(), nums.end(), val);
        return iter-nums.begin();
    }
};
