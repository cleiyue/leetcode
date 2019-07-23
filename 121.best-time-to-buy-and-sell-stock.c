/*
 * @lc app=leetcode id=121 lang=c
 *
 * [121] Best Time to Buy and Sell Stock
 */

int maxProfit(int *prices, int pricesSize) {
    int minprice = 2147483647;
    int maxprofit = 0;
    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < minprice) {
            minprice = prices[i];
        } else if (prices[i] - minprice > maxprofit) {
            maxprofit = prices[i] - minprice;
        }
    }
    return maxprofit;

    // if (pricesSize < 2) {
    //     return 0;
    // }
    // int ans = 0;
    // int indicate = 1;
    // int min = prices[0], max = 0;
    // while (true) {
    //     for (int i = 0; i < indicate; i++) {
    //         if (prices[i] < min) {
    //             min = prices[i];
    //         }
    //     }
    //     for (int i = indicate; i < pricesSize; i++) {
    //         if (prices[i] > max) {
    //             max = prices[i];
    //         }
    //     }
    //     if (ans < max - min) {
    //         ans = max - min;
    //     }
    //     indicate++;
    //     max = 0;
    //     if (indicate == pricesSize) {
    //         break;
    //     }
    // }
    // if (ans < 0) {
    //     return 0;
    // } else {
    //     return ans;
    // }
}
