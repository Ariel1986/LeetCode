/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
Example:
Given nums = [-2, 0, 3, -5, 2, -1]
sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
1. You may assume that the array does not change.
2. There are many calls to sumRange function.
Tags: dynamic programming
*/

//Code:
class NumArray {
public:
    NumArray(vector<int> &nums) : sums(nums) {
        for(int i = 1, iEnd = sums.size(); i < iEnd; ++i )
        {
            sums[i] += sums[i-1];
        }
    }

    int sumRange(int i, int j) {
        if(i < 0 || j > sums.size() -1 || i > j) return 0;
        return (i == 0)? sums[j] : sums[j] - sums[i-1];
    }
private:
    std::vector<int> sums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
