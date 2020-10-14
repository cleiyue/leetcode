/*
 * @lc app=leetcode id=714 lang=c
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start

#define MAX(a, b) a > b ? a : b

int maxProfit(int* prices, int pricesSize, int fee) {
    //不持有股票时的最大利润，持有股票时的最大利润
    int cash = 0, hold = -prices[0];
    for (int i = 0; i < pricesSize; i++) {
        cash = MAX(cash, hold + prices[i] - fee);
        hold = MAX(hold, cash - prices[i]);
    }
    return cash;
}
// @lc code=end
