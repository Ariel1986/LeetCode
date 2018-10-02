/*
Implement atoi to convert a string to an integer.
Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
spoilers alert... click to show requirements for atoi.
Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
Subscribe to see which companies asked this question.
*/

//==================Code============
class Solution {
public:
    int myAtoi(std::string str) {
        if(str.empty()) return 0;
        long long result = 0;
    
        const std::size_t sLen = str.size();
        int pos = 0;
        while(pos < sLen){
            if(str[pos] == ' ' || str[pos] == '\t'){
                ++pos;
            }
            else {
                break;
            }
        }
    
        if(pos == sLen) {
            return 0;
        }
        int sign = 1;
        if(str[pos] == '-'){
            sign = -1;
            ++pos;
        }
        else if(str[pos] == '+'){
            ++pos;
        }
    
        if(str[pos] < '0' || str[pos] > '9') {
            return 0;
        }
        while(pos < sLen){
            if(str[pos] >= '0' && str[pos] <= '9'){
                result = result * 10 + (str[pos] - '0');
                if((sign == 1 && result > INT_MAX) || (sign == -1 && (-result) <= INT_MIN)){
                    break;
                }
                ++pos;
            }
            else {
                break;
            } 
        }
        
        result *= sign;
        if(result <= INT_MIN){
            result = INT_MIN;
        }
        if(result >= INT_MAX){
            result = INT_MAX;
        }
        return result;
    }
};
