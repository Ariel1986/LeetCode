/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.
Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
/*思路：
方法一：
想求得只买卖一次的时候可获得的最大值，从前向后，profits[i] = std::max(profits[i - 1], prices[i] - buyPrice);
然后从最后向前，求买卖2次的最大值，令最终结果为一次还是2次买卖的最大值
方法二：
分别求0-i， i-iEnd-1的区间最大值，然后求两者和的最大值
*/

//
//Code 1:
int maxProfit(vector<int>& prices) {
    if(prices.size() < 2) return 0;
    
    std::vector<int> profits(prices.size(), 0);

    for (int i = 1, iEnd = prices.size(), buyPrice = prices[0]; i < iEnd; ++i)
    {
        if (prices[i] < buyPrice) buyPrice = prices[i];
        profits[i] = std::max(profits[i - 1], prices[i] - buyPrice);
    }

    int maxProfit = profits.back();
    for (int i = prices.size() - 1, salePrice = prices.back(); i > 0; --i)
    {
        salePrice = std::max(salePrice, prices[i]);
        maxProfit = std::max(maxProfit, salePrice - prices[i] + profits[i-1]);
    }
    return maxProfit;
}

//Code 2: : Time Limit Exceeded
int maxProfit(vector<int>& prices) {
    auto calMaxProfit = [](std::vector<int>& prices, int beg, int end) ->int
    {
        int buyPrice = INT_MAX;
        int maxProfit = 0;
        for (int i = beg; i < end; ++i)
        {
            if (prices[i] < buyPrice)
                buyPrice = prices[i];
            else
                maxProfit = std::max(prices[i] - buyPrice, maxProfit);
        }
        return maxProfit;
    };

    int result = 0;
    for (int i = 0, iEnd = prices.size(); i < iEnd; ++i)
        result = std::max(result, calMaxProfit(prices, 0, i+1) + calMaxProfit(prices, i + 1, iEnd));

    return result;
}

    int result = 0;
    for (int i = 0, iEnd = prices.size(); i < iEnd; ++i)
        result = std::max(result, calMaxProfit(prices, 0, i) + calMaxProfit(prices, i + 1, iEnd-1));

    return result;
}
