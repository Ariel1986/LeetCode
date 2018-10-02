/*Question:
Given two arrays, write a function to compute their intersection.
Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
Note:
Each element in the result must be unique.
The result can be in any order.
Tags: Binary Search, Hash Table, Two Pointers Sort
Similar Problems: (E) Intersection of Two Arrays II
*/

/**/

//Code:
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() || nums2.empty())
            return {};
            
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        
        vector<int> result;
        int sz1 = nums1.size(), sz2 = nums2.size();
        int i = 0, j = 0;
        while(i < sz1 && j < sz2)
        {
            if(nums1[i] < nums2[j])
                ++i;
            else if(nums1[i] > nums2[j])
                ++j;
            else
            {
                result.emplace_back(nums1[i]);
                while(i < sz1 && nums1[i] == nums1[++i])
                    ;
                while(j < sz2 && nums2[j] == nums2[++j])
                    ;
            }
        }
        return result;  
    }
};

//Code2:
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> result;
        std::unordered_set<int> s;
        for(auto&& num : nums2)
            s.emplace(num);
        
        for(auto&& num : nums1)
        {
            auto iter = s.find(num);
            //或者用std的find函数
            //auto iter = std::find(s.begin(), s.end(), num);
            if(iter != s.end())
            {
                result.emplace_back(num);
                s.erase(iter);
            }
        }
        return result;  
    }
};
