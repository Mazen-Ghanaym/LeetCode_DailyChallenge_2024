class Solution
{
public:
#define ll long long
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool isperfect(int n)
    {
        ll sq = sqrt(n);
        return sq * sq == n;
    }
    vector<vector<int>> dp;
    int rec(int idx, int n, vector<int> &perfect)
    {
        if (idx == perfect.size())
            return n;
        int &ret = dp[idx][n];
        if (~ret)
            return ret;
        ret = 1e9;
        for (int i = 0; 1; i++)
        {
            if (perfect[idx] * i <= n)
                ret = min(ret, i + rec(idx + 1, n - perfect[idx] * i, perfect));
            else
                break;
        }
        return ret;
    }
    int numSquares(int n)
    {
        vector<int> perfect;
        for (int i = 2; i <= n; i++)
            if (isperfect(i))
                perfect.push_back(i);

        dp = vector<vector<int>>(perfect.size(), vector<int>(n + 5, -1));
        return min(n, rec(0, n, perfect));
    }
};