class Solution
{
public:
    vector<int> dp;
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        dp = vector<int>(46, -1);
    }

    int climbStairs(int n)
    {
        if (n <= 0)
            return (n == 0 ? 1 : 0);
        int &ret = dp[n];
        if (~ret)
            return ret;
        return ret = climbStairs(n - 1) + climbStairs(n - 2);
    }
};