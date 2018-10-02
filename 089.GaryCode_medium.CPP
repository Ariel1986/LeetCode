/* Question:
The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
Tag: BackTracking
*/

/* 思路
把结果保存在一个vector，由vector的最后一个元素开始与（1<<x）位的结果相加并保存在vector，最后vector即为所求元素
例如： n=3
结果： [0, 1, 3, 2, 6, 7, 5, 4]
*/

//Code:
class Solution {
public:
    vector<int> grayCode(int n) {
        if (n < 1) return{ 0 };
        vector<int> garyCodes{ 0 };

        int count = 1;
        int loopTime = std::pow(2, n) / 2;
        int addNum = 1;

        while (garyCodes.size() <= loopTime)
        {
            for (int i = garyCodes.size() - 1; i>= 0; --i)
                garyCodes.emplace_back(garyCodes[i] + addNum);

            addNum <<= 1;
        }

        return garyCodes;
    }
};
