/* Question:
Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

/*Method:
//--------------Method2-------------
DP：
dp[i, j]表示s[i...j]是否为回文子串，
dp[i,j] = true : s[i] == s[j] && s(i+1 ... j-1)是回文子串(即dp[i-1][j-1] == true)
当找到一个回文，就检查是否为最长的。时间复杂度O(n^2).
*/

//------------------Code1-------------------
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        int minStart = 0, maxLen = 1;
        for (int i = 0, iEnd = s.size(); i < iEnd; ++i){
            int j = i, k = i;
            if(s.size() - k <= maxLen / 2) break;
            while( k < iEnd - 1 && s[k + 1] == s[k]) {
                ++k;
            }
            while( j > 0 && k < iEnd - 1 && s[j - 1] == s[k + 1]){
                ++k;
                --j;
            }
            if(k - j + 1 > maxLen){
                maxLen = k - j + 1;
                minStart = j;
            }
        }
        
        return s.substr(minStart, maxLen);
    }
};

//------------------code2---------------------
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        int minStart = 0, maxLen = 1;
        for (int i = 0, iEnd = s.size(); i < iEnd; ++i){
            int j = i, k = i;
            if(s.size() - k <= maxLen / 2) break;
            //奇数个
            while( j > 0 && k < iEnd - 1 && s[j - 1] == s[k + 1]){
                ++k;
                --j;
            }
            if(k - j + 1 > maxLen){
                maxLen = k - j + 1;
                minStart = j;
            }
            
            //偶数个
            j = i, k = i + 1;
            while( j >= 0 && k < iEnd && s[j] == s[k]){
                ++k;
                --j;
            }
            if(k - j - 1 > maxLen){
                maxLen = k - j - 1;
                minStart = j + 1;
            }
        }
        
        return s.substr(minStart, maxLen);
    }
};

//-------------------Code3--------------------
class Solution {
public:
std::string longestPalindrome(std::string s) {
    if(s.size() <= 1) return s;
    
    int start = 0, maxLen = 1;
    int sLen = s.size();
    int dp[sLen][sLen];
    
    for(int i = 0; i < sLen; ++i){
        for(int j = 0; j < sLen; ++j){
            dp[i][j] = 0;
        }
    }
    
    for(int i = 0; i < sLen; ++i){
        dp[i][i] = 1;
        
    }
    for(int i = 0, iEnd = sLen-1; i < iEnd; ++i){
        if(s[i] == s[i+1]){
            dp[i][i+1] = 1;
            start = i;
            maxLen = 2;
        }
    }
    
    for(int len = 3; len <= sLen; ++len){
        for(int i = 1, iEnd = sLen - len + 2; i < iEnd; ++i){
            if(dp[i][i+len-3] == 1 && s[i-1] == s[i+len-2]){
                dp[i-1][i+len-2] = 1;
                start = i-1;
                maxLen = len;
            }
        }
    }
    
    return s.substr(start, maxLen);
}
};
