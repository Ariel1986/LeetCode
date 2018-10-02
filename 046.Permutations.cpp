/*
Given a collection of distinct numbers, return all possible permutations.
For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
Tags:  Backtracking
*/

//Code:
//Code 1:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()) return {};
        std::vector<std::vector<int>> result;
        
        std::function<void(std::vector<int>&, std::vector<std::vector<int>>&, int, int)>
        permuteHelper = 
            [&](std::vector<int>& nums, std::vector<std::vector<int>>& result, int beg, int end)
        {
            if(beg == end)
            {
                result.emplace_back(nums);
                return;
            }
            
            for(int i = beg; i < end; ++i)
            {
                std::swap(nums[i], nums[end - 1]);
                permuteHelper(nums, result, beg, end - 1);  // The important is end-1, not beg + 1
                std::swap(nums[i], nums[end - 1]);
            }
        };
        
        permuteHelper(nums, result, 0, nums.size());
        return result;
    }
    
//Code 2:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()) return {};
        
        std::vector<std::vector<int>> result{{nums[0]}};
        
        for(int i = 1, iEnd = nums.size(); i < iEnd; ++i)
        {
            int sz = result.size();
            std::vector<int> temp(result[0].size()+1);
            for(int j = 0, jNum = result[j].size(); j < sz; ++j)
            {
                for(int k = 0; k <= jNum; ++k)
                {
                    int m = 0;
                    for(; m < k; ++m)
                        temp[m] = result[j][m];
                    temp[m++] = nums[i];
                    for(; m <= jNum; ++m)
                        temp[m] = result[j][m-1];
                    result.emplace_back(temp);
                }
            }
            for(int j = 0; j < sz; ++j)
                result.erase(result.begin());
        }
        return result;
    }
