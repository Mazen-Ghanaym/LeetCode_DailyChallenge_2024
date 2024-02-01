class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    // hint: dp with prefix sum trick
    const int MOD = 1e9 + 7;
    int kInversePairs(int n, int k)
    {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            vector<int> pref(k + 2);

            for (int j = 0; j <= k; j++)
            {
                pref[j + 1] = (pref[j] + dp[i - 1][j]) % MOD;
            }

            for (int j = 0; j <= k; j++)
            {
                dp[i][j] = (pref[j + 1] - pref[j - min(i - 1, j)] + MOD) % MOD;
            }
        }
        return dp[n][k];
    }
};