class Solution
{
public:
    vector<vector<long long>> dp;
    bool isvalid(int i, int j, int n)
    {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long min_val(int i, int j, vector<vector<int>> &grid)
    {
        if (i == grid.size())
            return 0;
        if (!isvalid(i, j, grid.size()))
            return 1e17;
        long long &ret = dp[i][j];
        if (ret != -1e17)
            return ret;
        ret = 1e17;
        for (int k = 0; k < grid.size(); k++)
        {
            if (k == j)
                continue;
            ret = min(ret, min_val(i + 1, k, grid));
        }
        if (ret == 1e17)
            ret = 0;
        ret += grid[i][j];
        return ret;
    }
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        dp = vector<vector<long long>>(n, vector<long long>(n, -1e17));
        long long mnv = 1e17;
        for (int i = 0; i < n; i++)
        {
            mnv = min(mnv, min_val(0, i, grid));
        }
        return mnv;
    }
};