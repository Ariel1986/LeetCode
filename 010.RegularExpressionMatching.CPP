/* 
Implement regular expression matching with support for '.' and '*'.
'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
The function prototype should be:
bool isMatch(const char *s, const char *p)
Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
Tags: Dynamic Programming, backtracking
*/

/* Method
//=================Method1================
递归
//=================Method2================
DP
1, If p[j] == s[i] :  dp[i][j] = dp[i-1][j-1];
2, If p[j] == '.'  : dp[i][j] = dp[i-1][j-1];
3, If p[j] == '*': 
   here are two sub conditions:
               1   if p[j-1] != s[i] : dp[i][j] = dp[i][j-2]  //in this case, a* only counts as empty
               2   if p[j-1] == s[i] or p[j-1] == '.':
                              dp[i][j] = dp[i-1][j]    //in this case, a* counts as multiple a 
                           or dp[i][j] = dp[i][j-1]   // in this case, a* counts as single a
                           or dp[i][j] = dp[i][j-2]   // in this case, a* counts as empty
*/

//=================code1================
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())    return s.empty();
        
        if ('*' == p[1])
            // x* matches empty string or at least one character: x* -> xx*
            // isMatch(s, p.substr(2): x* matches empty string 
            // !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p): x* matches at least one character: x* -> xx*
            return (isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
        else
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
    }
};

//=================code2=================
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())    return s.empty();
        int sLen = s.size(), pLen = p.size();
        vector<vector<int>> dp(sLen+1, vector<int>(pLen + 1, false));

        dp[0][0] = true;
        
        for(int j = 1; j < pLen; ++j){
            if(p[j] == '*' && dp[0][j-1]){
                dp[0][j+1] = true;
            }
        }
        
        for(int i = 0; i < sLen; ++i)
            for(int j = 0; j < pLen; ++j){
                if(s[i] == p[j] || p[j] == '.'){
                    dp[i+1][j+1] = dp[i][j];
                }
                else if(p[j] == '*'){
                    if(p[j-1] != s[i] && p[j-1] != '.'){
                        dp[i+1][j+1] = dp[i+1][j-1];
                    } else{
                        dp[i+1][j+1] = (dp[i+1][j] || dp[i][j+1] || dp[i+1][j-1]);
                    }
                }
            }
        return dp[sLen][pLen];
    }
};

