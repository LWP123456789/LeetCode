/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int min_prince = inf,max_profit = 0;
        for (int price : prices)
        {
            min_prince = min(min_prince,price);
            max_profit = max(price - min_prince,max_profit);
        }
        return max_profit;
    }
};
// @lc code=end

/*
    1、1e9代表一个很大的数，常用来做初始化操作；
    2、运用max()、min()方法取得最大最小值存储
*/