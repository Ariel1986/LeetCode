/*Question:
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
*/

//Code:
int romanToInt(string s) {
    if(s.length() <= 0) return 0;
    
    std::unordered_map<char, int> mapHelp{{'I', 1}, {'V', 5}, {'X',10}, {'L',50 }, {'C',100 }, {'D',500}, {'M',1000}};
    
    unsigned int result = mapHelp[s.back()];
    unsigned int pre = result;
    
    for(int i = s.length() - 2; i >= 0; --i)
    {
        unsigned int cur = mapHelp[s[i]];
        if(mapHelp[s[i]] < mapHelp[s[i + 1]])
            result -= mapHelp[s[i]];
        else
            result += mapHelp[s[i]];
    }
    
    return result;
}
