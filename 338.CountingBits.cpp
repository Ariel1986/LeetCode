/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
Example:
For num = 5 you should return [0,1,1,2,1,2].
Follow up:
It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
Hint:
You should make use of what you have produced already.
Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try to generate new range from previous.
Or does the odd/even status of the number help you in calculating the number of 1s?
Tags: Dynamic Programming, Bit Manipulation
*/

/*思路:
方法一:
按照提示对元素进行分组，[2-3], [4-7], [8-15]...每一组都是{result[0]+1, result[1]+1...},每到遇到2的次幂，就从头开始加
方法二:
j的位置也可以直接通过i&(i-1)来获得
*/

//Code:
//Code 1:
class Solution {
public:
    vector<int> countBits(int num) {
        std::vector<int> bitsArray(num + 1);
        bitsArray[0]=0;
        int i = 1, j = 0;
        
        for(;i <= num;i++)
        {
            if((i & (i - 1)) == 0)
                j = 0;
            bitsArray[i]=bitsArray[j]+1;
            j++;
        }
        return bitsArray;
    }
};

//Code 2:
std::vector<int> countBits(int num)
{
    std::vector<int> result{0};
    
    for (int i = 1; i <= num; ++i)
    {
        result.emplace_back(result[(i-1)&i]+1);
    }
    
    return result;
}
