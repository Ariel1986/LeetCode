/*Question:
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
This is case sensitive, for example "Aa" is not considered a palindrome here.
Note:
Assume the length of given string will not exceed 1,010.
Example:
Input:
"abccccdd"
Output:
7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
Tags: Hash Table
*/

//Code:
int longestPalindrome(string s) {
    if(s.size() < 1) return 0;
    int result = 0;
    bool flag = false;
    std::unordered_map<char, int> m;
    for(auto&& ch : s)
    {
        if(m.find(ch) != m.end())
        {
            ++m[ch];
        }
        else
        {
            m.emplace(std::make_pair(ch, 1));
        }
    }
    
    for(auto&& item : m)
    {
        result += item.second;
        if(item.second % 2 != 0)
        {
            --result;
            flag = true;
        }
    }
    
    if(flag)
        ++result;
    
    
    return result;
}
