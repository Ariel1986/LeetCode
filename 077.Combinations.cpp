/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
For example,
If n = 4 and k = 2, a solution is:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
SP: 39, 46
*/

//Code:
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(n < 1 || k < 1)
            return {{}};
        std::vector<std::vector<int>> result;
        std::vector<int> combination;
        
        std::function<void(std::vector<std::vector<int>>&, std::vector<int>&, int, int, int)>
        combineHelp = [&](std::vector<std::vector<int>>& result, std::vector<int>& combination, int curN, int n, int k)
        {
            if(combination.size() == k)
            {
                result.emplace_back(combination);
                return;
            }
            for(int i = curN; i <= n; ++i)
            {
                combination.emplace_back(i);
                combineHelp(result, combination, i+1, n, k);
                combination.pop_back();
            }
        };
        
        combineHelp(result, combination, 1, n, k);
        return result;
    }
};
