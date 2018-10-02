/* Question:
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

/* 思路：
贪心算法
输入：[6,1,3,2,4,7]
输出：7
由于可以买卖多次，遍历每个元素，只要当前元素后面的值比当前值大，就将两者的差加到返回结果
*/

// Code:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    std::vector<int>::size_type sz = prices.size();
         if (sz <= 1) return 0;
 
         int profit = 0;
         for (std::vector<int>::size_type i = 0; i < sz -1; ++i)
         {
             if (prices[i] < prices[i+1])
                 profit += prices[i+1] - prices[i];
         }
         return profit;
     }
};
