/*
 * @lc app=leetcode id=122 lang=c
 *
 * [122] Best Time to Buy and Sell Stock II
 */

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 2) return 0;
    int maxprofit = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > prices[i - 1])
            maxprofit += prices[i] - prices[i - 1];
    }
    return maxprofit;
}
