class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1);
        for (int i = 0; i < n; i++)
        {
            int mxv = 0, sum = 0;
            for (int j = i; j >= max(0, i - k + 1); --j)
            {
                mxv = max(mxv, arr[j]);
                int newsum = mxv * (i - j + 1) + dp[j];
                sum = max(newsum, sum);
            }
            dp[i + 1] = sum;
        }
        return dp[n];
    }
};