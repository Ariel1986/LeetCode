/* Question:
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
For example:
Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

/* Method:
对所有元素做异或操作，那么最后得到的值就是要求的两个元素异或得到的，
找出其中为1的某一位，说明这一位两个数一个为0，一个为1，以这一位为标准，把数组的元素分为两组A、B，
要求的两个元素肯定是一个在A组，一个在B组，而对这两组各自做异或操作，就可以得到两个数就是要求的。
*/

//Code:
vector<int> singleNumber(vector<int>& nums) {
    std::vector<int> res = {0, 0};
    
    for (auto && num : nums) 
    {
        res[0] ^= num;
    }
    
    int pos = 0;
    int offset = 1;
    while ((res[0] & offset) != offset) 
    {
        ++pos;
        offset <<= 1;
    }
    
    res[0] = 0;
    int mask = 1 << pos;
    for (int i = 0; i < nums.size(); i++) 
    {
        if ((mask & nums[i]) == mask) 
        {
            res[0] ^= nums[i];
        } 
        else 
        {
            res[1] ^= nums[i];
        }
    }
    return res;
}
