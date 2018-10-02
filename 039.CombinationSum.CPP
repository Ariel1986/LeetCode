/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
The same repeated number may be chosen from C unlimited number of times.
Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
Tags: Array, Backtracking
*/

/* 思路：
必须先排序原数组，不然在如下例子中会发生错误：
Input:
[8,7,4,3]
11
Output:
[]
Expected:
[[3,4,4],[3,8],[4,7]]
*/

//Code:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> temp;
        
        // Must sort the array first
        std::sort(candidates.begin(), candidates.end());
        
        std::function<void(int, int, int)>
        combinationSumHelper = [&](int start, int end, int sum)
        {
            if(sum == target)
            {
                result.emplace_back(temp);
            }
            else if(sum > target)
                return;
            
            for(int i = start; i <= end; ++i)
            {
                sum += candidates[i];
                if(sum > target)
                    break;
                    
                temp.emplace_back(candidates[i]);
                combinationSumHelper(i, end, sum);
                temp.pop_back();
                sum -= candidates[i];
            }
        };
        
        combinationSumHelper(0, candidates.size() - 1, 0);
        
        return result;
    }
