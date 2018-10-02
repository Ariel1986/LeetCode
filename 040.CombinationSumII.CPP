/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. 
Each number in C may only be used once in the combination. 
Note:
•All numbers (including target) will be positive integers.
•The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
 A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Tags: Array Backtracking 
*/

//Code:
 vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
     if (candidates.empty()) return{ {} };

     std::vector<std::vector<int>> result;
     std::vector<int> temp;

     std::function<void(int, int, int)>
         combinationSum2Helper = [&](int start, int end, int sum)
     {
         if (sum == target)
             result.emplace_back(temp);
         else if (sum > target)
             return;
         for (int i = start; i <= end; ++i)
         {
             //Remember this judge
             if (i != start && candidates[i] == candidates[i - 1])
                 continue;
             sum += candidates[i];
             if (sum > target)
                 return;
             temp.emplace_back(candidates[i]);
             combinationSum2Helper(i + 1, end, sum);
             sum -= candidates[i];
             temp.pop_back();
         }
     };

     std::sort(candidates.begin(), candidates.end());
     combinationSum2Helper(0, candidates.size() - 1, 0);
     return result;
 }
