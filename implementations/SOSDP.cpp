for (int i = 0; i < (1<<n); i++)
    dp[i] = A[i];
for (int i = 0; i < n; i++) {
    for (int m = 1; m < (1<<n); m++) {
        if (m & (1<<i))
            dp[m] += dp[m ^ (1<<i)];
    }
}
