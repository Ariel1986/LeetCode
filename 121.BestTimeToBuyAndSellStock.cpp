/* Question:
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Tag: Array, Dynamic programming
*/

/*思路：
1）当前元素比minPriceEndingHere大，当前元素可能为要卖股票的元素，maxProfitSofar = std::max(maxProfitSofar, prices[i]-minPriceEndingHere);
2）当前元素比minPriceEndingHere小，令minPriceEndingHere=prices[i],;
*/

// Code:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>::size_type sz = prices.size();
        if (sz <= 1) return 0;

        int minPriceEndingHere = prices[0], maxProfitSofar = 0;
        for (vector<int>::size_type i = 1; i < sz; ++i)
        {
            int price = prices[i];
            if (price > minPriceEndingHere)
            {
                maxProfitSofar = std::max(maxProfitSofar, price-minPriceEndingHere);
            }
            else
            {
                minPriceEndingHere = price;
            }
        }
        return maxProfitSofar;
    }
};
