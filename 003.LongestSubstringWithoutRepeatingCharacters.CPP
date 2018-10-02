/* Question:
Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
Subscribe to see which companies asked this question.
Hide Tags Hash Table Two Pointers String
Hide Similar Problems (H) Longest Substring with At Most Two Distinct Characters
*/

/* Method:
借助DP的方法实现：
假设L[i-1]（start，maxLen）是访问s[i]前最长的元素列表
1）元素s[i]不在最长列表L中，将s[i]添加到最长的元素列表L中；则maxLen加1，start不改变，将s[i]最后一次出现的位置记录在mHash中；
2）元素s[i]在mHash中存在，令start=std::max(mHash[s[i]], start); 然后maxLen = std::max(maxLen, i - start);
*/

//===========Code1==========
class Solution {
public:
int lengthOfLongestSubstring(std::string s) {
    int maxLen = 0, start = -1;
    std::vector<int> dict(256, -1);
    
    for(int i = 0, iEnd = s.size(); i < iEnd; ++i){
        if (dict[s[i]] > start){
            start = dict[s[i]];
        }
        dict[s[i]] = i;
        maxLen = std::max(maxLen, i - start);
    }
    return maxLen;
}
};

//===========Code2==========
class Solution {
public:
int lengthOfLongestSubstring(std::string s) {
    int maxLen = 0, start = -1;
    std::unordered_map<char, int> mHash;
    
    for(int i = 0, iEnd = s.size(); i < iEnd; ++i){
        if (mHash.find(s[i]) != mHash.end()){
            start = std::max(mHash[s[i]], start);
        }
        mHash[s[i]] = i;
        maxLen = std::max(maxLen, i - start);
    }
    return maxLen;
}
};
