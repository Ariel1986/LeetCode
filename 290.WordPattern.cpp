/* Question:
Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/
//Code 1:
bool wordPattern(string pattern, string str) {
    std::unordered_map<char, std::string> pattern_str;
    std::unordered_map<std::string, char> str_pattern;
    int i = 0, iEnd = pattern.length(),j = 0, jEnd = str.length();
    
    for(; i < iEnd && j < jEnd; ++i, ++j)
    {
        std::string tmp;
        while(j < jEnd && str[j] != ' ')
        {
            tmp += str[j];
            ++j;
        }
        
        auto p1 = pattern_str.emplace(std::make_pair(pattern[i], tmp));
        if(!p1.second && tmp.compare(pattern_str[pattern[i]]) != 0)
        {
            return false;
        }
        
        auto p2 = str_pattern.emplace(std::make_pair(tmp, pattern[i]));
        if(!p2.second && str_pattern[tmp] != pattern[i])
        {
            return false;
        }
    }
    
    if(i != iEnd || j != jEnd + 1)  //Notice: Here the j is != jEnd+1
        return false;
    
    return true;
}
//Code 2:
bool wordPattern(std::string pattern, std::string str)
{
    std::vector<std::string> words;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, ' '))
    {
        words.emplace_back(token);
    }
    
    std::unordered_map<char, std::string> dict_pattern;
    std::unordered_map<std::string, char> dict_word;
    
    if (pattern.size() != words.size()) return false;
    
    for (int i = 0, iEnd = (int)pattern.size(); i < iEnd; ++i)
    {
        
        if (dict_pattern.find(pattern[i]) == dict_pattern.end())
        {
            dict_pattern[pattern[i]] = words[i];
        }
        
        if (dict_word.find(words[i]) == dict_word.end())
        {
            dict_word[words[i]] = pattern[i];
        }
        
        if (dict_pattern[pattern[i]] != words[i] || dict_word[words[i]] != pattern[i])
        {
            return false;
        }
    }

    return true;
}
