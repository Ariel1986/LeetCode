/* Question:
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
Example:
Input:
[4,3,2,7,8,2,3,1]
Output:
[5,6]
*/

/*思路:
利用特有的：数组中的元素1 ≤ a[i] ≤ n这一特点
*/

//Code:
vector<int> findDisappearedNumbers(vector<int>& nums) {
    std::vector<int> res;
    for(int i = 0, iEnd = nums.size(); i < iEnd; ++i){
        nums[(nums[i] - 1) % iEnd] += iEnd;
    }
    
    for(int i = 0, iEnd = nums.size(); i < iEnd; ++i){
        if(nums[i] <= iEnd){
            res.emplace_back(i + 1);
        }
    }
    return res;
}
