/*
 * @lc app=leetcode id=122 lang=c
 *
 * [122] Best Time to Buy and Sell Stock II
 */

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 2) return 0;
    int valley = prices[0], peak = prices[0], maxprofit = 0, i = 0;
    while (i < pricesSize - 1) {
        while (i < pricesSize - 1 && prices[i] >= prices[i + 1]) {
            i++;
        }
        valley = prices[i];
        while (i < pricesSize - 1 && prices[i] <= prices[i + 1]) {
            i++;
        }
        peak = prices[i];
        maxprofit += peak - valley;
    }
    return maxprofit;
}
