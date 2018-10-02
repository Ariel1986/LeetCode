/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

/*思路：
由于对数组nums1存在第一个元素是nums2的情况，所以逆序存储元素，从尾部开始处理
*/

//Code:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        
        for(int k = m + n - 1; k >= 0 && i >= 0 && j>= 0; --k)
        {
            if(nums1[i] > nums2[j])
                nums1[k] = nums1[i--];
            else 
                nums1[k] = nums2[j--];
        }
        
        if(i < 0)
        {
            i = 0;
            for(int k = 0; k <= j; ++k)
                nums1[i++] = nums2[k];
        }
        return;
    }
