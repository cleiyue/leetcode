/*
 * @lc app=leetcode id=204 lang=c
 *
 * [204] Count Primes
 */

int countPrimes(int n) {
    if (n <= 2) return 0;
    int *isPrime = calloc(n, sizeof(int));
    int count = 1;
    for (int i = 3; i < n; i += 2) {
        if ((long int)i * (long int)i < (long int)n) {
            if (isPrime[i]) continue;
            for (int j = i * i; j < n; j += i * 2) {
                isPrime[j] = 1;
            }
        }
        if (!isPrime[i]) count++;
    }
    return count;
}
