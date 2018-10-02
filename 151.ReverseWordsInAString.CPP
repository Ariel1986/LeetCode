/* Question:
Given an input string, reverse the string word by word.
For example,
Given s = "the sky is blue",
return "blue is sky the".
Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.
click to show clarification.
Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/

/* Method:
本题的难点是处理开头／结尾／中间部分的空格
*/

//Code:
void reverseWords(string &s) {
    if(s.size() < 1) return;
    
    //handle the spaces
    // erase leading spaces
    auto firstNonSpaceChar = s.find_first_not_of(" ");
    s.erase(0, firstNonSpaceChar);
    if (s.empty()) return;
    
    // erase trailing spaces
    auto lastNonSpaceChar = s.find_last_not_of(" ");
    if (lastNonSpaceChar+1 < s.size())
        s.erase(lastNonSpaceChar+1);
    
    //Reduce multiple spaces between two words to a single space in the reversed string multiple spaces between two words
    int index = 1;
    for(int i = 1, iEnd = s.size(); i < iEnd; ++i)
    {
        if(s[i] == ' ' && s[i] == s[i - 1])
            continue;
        s[index++] = s[i];
    }
    
    s.erase(index);
   
    std::reverse(s.begin(), s.end());
    
    for(int i = 0, iEnd = s.size(); i < iEnd; )
    {
        int tmp = i + 1;
        while(tmp < iEnd && s[tmp] != ' ')
            ++tmp;
        std::reverse(s.begin() + i, s.begin() + tmp);
        i = tmp + 1;
    }
    
    return;
}
