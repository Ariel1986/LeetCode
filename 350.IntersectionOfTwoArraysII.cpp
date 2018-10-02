/*Question:
Given two arrays, write a function to compute their intersection.
Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
Tags: Binary Search, Hash Table, Two Pointers, Sort
Similar Problems: 349
*/

/*思路:
*/

//Code:
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() || nums2.empty())
            return {};
        
        std::vector<int> result;
        for(auto&& num : nums1)
        {
            auto iter = std::find(nums2.begin(), nums2.end(), num);
            if(iter != nums2.end())
            {
                result.emplace_back(num);
                nums2.erase(iter);
            }
        }
        
        return result;
    }
};
