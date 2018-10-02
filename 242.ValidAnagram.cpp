/*Question:
Given two strings s and t, write a function to determine if t is an anagram of s.
For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.
Note:
You may assume the string contains only lowercase alphabets.
Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
Tags: Hash table, sort
similar problems: 49
*/

/*思路:
方法一:排序
方法二:哈希表
*/

//Code:
//Code 1:
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::sort(std::begin(s), std::end(s));
        std::sort(std::begin(t), std::end(t));
        return s.compare(t) == 0;
    }
};

//Code 2:
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::vector<int> check(26, 0);
        for(auto item : s)
            check[item - 'a']++;
        for(auto item : t)
            check[item - 'a']--;
        for(auto item : check)
            if(item != 0) 
                return false;
        return true;
    }
};
