/* Question:
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
Each LED represents a zero or one, with the least significant bit on the right.
For example, the above binary watch reads "3:25".
Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
Example:
Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
Tags: Backtracking, Bit Manipulation
*/

//Method:
方法一：An alternative is to understand that 4 bits represent all possible hours [0,12), 6 bits represent all possible minutes [0,59). We just go through all possible combination.

//Code:
//Code 1:
vector<string> readBinaryWatch(int num) {
    std::vector<std::string> result;
    
    for(int i = 0; i <12; ++i)
    {
        bitset<4> h(i);
        for(int j = 0; j < 60; ++j)
        {
            bitset<6> s(j);
            if(h.count() + s.count() == num)
            {
                result.emplace_back(std::to_string(i) + (j < 10? ":0" : ":") + std::to_string(j));
            }
        }
    }
    
    return result;
}

//Code 2:
//[0-1024) represents all possible binary cases(2 to the power of 10) for this question.
vector<string> readBinaryWatch(int num) {
    vector<string> ret;
    for (int i = 0; i < 1024; ++i) {
        bitset<10> temp((size_t) i);
        if (temp.count() != num)continue;
        int h{}, m{}, candiate{i};
        for (int j = 0; j < 4; ++j, candiate >>= 1) if (candiate & 1)h += pow(2, j);
        if (h >= 12)continue;
        for (int k = 0; k < 6; ++k, candiate >>= 1)if (candiate & 1)m += pow(2, k);
        if (m >= 60)continue;
        ret.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
    }
    return ret;
}
