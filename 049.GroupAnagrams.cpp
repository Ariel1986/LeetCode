/*
Given an array of strings, group anagrams together.
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.
Tags: hash table, string
*/

//Code:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::vector<std::vector<std::string>> result;
    std::unordered_map<std::string, std::vector<std::string>> m;

    for (int i = 0, iEnd = strs.size(); i < iEnd; ++i)
    {
        std::string s(strs[i]);
        std::sort(s.begin(), s.end());
        m[s].emplace_back(strs[i]);
    }

    for (auto&& item : m)
        result.push_back(item.second);
        
    return result;
  }
