/*
 * @lc app=leetcode id=204 lang=c
 *
 * [204] Count Primes
 */

bool isPrime(int n) {
    int k = (int)sqrt((double)n);
    for (int i = 2; i <= k; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int countPrimes(int n) {
    int ans = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            ans++;
        }
    }
    return ans;
}
