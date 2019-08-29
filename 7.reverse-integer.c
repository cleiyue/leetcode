/*
 * @lc app=leetcode id=7 lang=c
 *
 * [7] Reverse Integer
 */

int reverse(int x){
    long int ans = 0;
    while(x){
        ans *= 10;
        ans += x%10;
        if(ans > INT_MAX || ans < INT_MIN) return 0;
        x /= 10;
    }
    return ans;
}
