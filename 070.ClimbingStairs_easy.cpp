/*Question:
ou are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

/*思路：
每层可以选择的上楼方式就是一个斐波那契数列，f(n) = f(n-1) + f(n-2)
如果用递归实现，可以需要很多的递归调用时间，会产生超时错误
借助一个vector保存前面的值，所以vector[i] = vector[i-1] + vector[i-2]
*/

//Code:
class Solution {
public:
    int climbStairs(int n) {
        if(n < 1) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        std::vector<int> climbingWay{0,1,2};
        for(int i = 3; i <= n; ++i)
        {
            climbingWay.emplace_back(climbingWay[i-1] + climbingWay[i-2]);
        }
        
        return climbingWay.back();
    }
};
