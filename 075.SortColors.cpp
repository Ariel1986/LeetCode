/*Question:
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
Note:
You are not suppose to use the library's sort function for this problem.
click to show follow up.
Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with an one-pass algorithm using only constant space?
*/

/*思路
方法一：
元素只有0,1,2三种情况，所以根据元素的特殊性，0值元素在数组的最前面，2值元素在数组的最后面，所以只需要在处理元素的过程中将遇到的0值元素放在
前面，2值元素放在最后面；对于1值元素最后处理。
方法二：
设置三个索引值，分别指示最前面0、1、2值存储的位置，如果当前元素为0，则先将值为2、值为1的元素后移一个，然后再存储值为0的元素；
同理处理值为1和2的情况。
*/

//Code:
//方法一:
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty()) 
            return;
        int begIndex = 0;
        int endIndex = nums.size() - 1;
        int i = 0, j = nums.size() - 1;
        while( i <= j)
        {
            while(i <= j && nums[i] == 0)
            {
                nums[begIndex++] = 0;
                ++i;
            }
            while(i <= j && nums[j] == 2)
            {
                nums[endIndex--] = 2;
                --j;
            }
            
            if(i < j)
            {
                int temp = nums[j];
                if(nums[i] == 2)
                    nums[endIndex--] = 2;
                if(temp == 0)
                    nums[begIndex++] = 0;
            }
           
            ++i; --j;
        }
        
        while(begIndex <= endIndex)
        {
            nums[begIndex] = 1;
            ++begIndex;
        }
        return;
    }
};

//方法2:
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty()) 
            return;
        
        int red = -1, white = -1, blue = -1;
        for(auto num: nums)
        {
            if(num == 0)
            {
                nums[++blue] = 2;
                nums[++white] = 1;
                nums[++red] = 0;
            }
            
            else if(num == 1)
            {
                nums[++blue] = 2;
                nums[++white] = 1;
            }
            else
                nums[++blue] = 2;
        }
        return;
    }
};
