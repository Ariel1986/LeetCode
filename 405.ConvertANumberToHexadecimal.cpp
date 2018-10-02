/* Question:
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.
Note:
All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
Example 1:
Input:
26
Output:
"1a"
Example 2:
Input:
-1
Output:
"ffffffff"
*/

//Code:
string toHex(int num) {
    if(num == 0) return "0";
    
    const int digits = 32;
    const int items = 4;
    const int group = digits / items;
    
    std::string result;
    std::vector<char> vec{'0', '1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    unsigned int filter = 0xf0000000;
    
    for(int i = 0; i < group; ++i)
    {
        unsigned int temp =((num & filter) >>28);
        result += vec[temp];
        num <<= 4;
    }
    
    auto iter = result.find_first_not_of('0');
    result.erase(0, iter);

    return result;
}
