/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

//Code:
//Code 1:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        
        std::string res = strs[0];
        auto longestCommonPrefixHelper = [&res] (std::string& str) mutable
        {
            int i = 0;
            int len1 = res.size(), len2 = str.size();
            while(i < len1 && i < len2 && str[i] == (res[i]))
                ++i;
            
            res = res.substr(0, i);
        };
        
        for(int i = 1, iEnd = strs.size(); i < iEnd; ++i)
        {
            if(strs[i].compare("") == 0) return "";
            if(strs[i].compare(res) == 0) continue;
            longestCommonPrefixHelper(strs[i]);
        }
        
        return res;
    }
    
//Code 2:
std::string longestCommonPrefix(std::vector<std::string>& strs)
{
    if (strs.empty()) return "";
    
    std::sort(strs.begin(), strs.end(), [](std::string &a, std::string &b) { return a.size() < b.size(); });
    
    std::string common = strs[0];
    for (auto&& str : strs)
    {
        int i = 0;
        for (int iEnd = (int)common.size(); i < iEnd; ++i)
        {
            if (common[i] != str[i])
                break;
        }
        common.erase(i);
    }
    
    return common;
}
