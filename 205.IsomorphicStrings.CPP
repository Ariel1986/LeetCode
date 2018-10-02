/*
Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character but a character may map to itself.
For example,
Given "egg", "add", return true.
Given "foo", "bar", return false.
Given "paper", "title", return true.
Note:
You may assume both s and t have the same length.
Tags: Hash Table
*/

/*思路：
方法一：
建立每一个字符串->字符串位置的哈希表，然后将哈希表的值组合成字符串（组合的过程中加入"#"以区分不同的字符对应的位置），然后比较两个字符串是否相同
方法二：
分别建立字符串s到字符串t的每个字符的对应关系和 字符串t到字符串s的每个字符的对应关系
*/

//Code:
//Code 1:
    bool isIsomorphic(string s, string t) {
        std::map<char, string> m1, m2;
        
        for(int i = 0, iEnd = s.size(); i < iEnd; ++i)
        {
            if(m1.find(s[i]) != m1.end())
                m1[s[i]] += '0' + i;
            else
             m1[s[i]] = '0' + i;
        }
        
        for(int i = 0, iEnd = t.size(); i < iEnd; ++i)
        {
            if(m2.find(t[i]) != m2.end())
                m2[t[i]] += '0' + i;
            else
                m2[t[i]] = '0' + i;
        }
        
        std::string s1;
        for(int i = 0, iEnd = m1.size(); i < iEnd; ++i)
        {
            s1 += m1[s[i]];
            s1 += "#";   //区分不同的行
        }
            
        std::string s2;
        for(int i = 0, iEnd = m2.size(); i < iEnd; ++i)
        {
            s2 += m2[t[i]];
            s2 += "#";
        }
        
        return s1.compare(s2) == 0;
    }
//Code 2:
bool isIsomorphic(string s, string t) {
    std::map<char, char> m1, m2;
    for (int i = 0, iEnd = s.size(); i < iEnd; ++i)
    {
        if (m1.find(s[i]) != m1.end() && t[i] != m1[s[i]])
            return false;
        else
            m1[s[i]] = t[i];
        if (m2.find(t[i]) != m2.end() && s[i] != m2[t[i]])
            return false;
        else
            m2[t[i]] = s[i];
    }
    return true;
}
