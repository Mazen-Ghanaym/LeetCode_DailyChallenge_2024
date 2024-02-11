class Solution
{
public:
    int dj[3] = {-1, 0, 1};
#define ll long long
    int dp[75][75][75];
    int n, m;
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool isvalid(int col1, int col2)
    {
        return col1 >= 0 && col1 < m && col2 >= 0 && col2 < m;
    }
    int rec(int i, int col1, int col2, vector<vector<int>> &grid)
    {
        if (i == n)
            return 0;
        if (!isvalid(col1, col2))
            return INT_MIN;
        // cout<<i<<" "<<col1<< " "<<col2<<"\n";
        int &ret = dp[i][col1][col2];
        if (~ret)
            return ret;
        ret = 0;
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                ret = max(ret, rec(i + 1, col1 + dj[x], col2 + dj[y], grid));
            }
        }
        ret += (col1 == col2 ? grid[i][col1] : grid[i][col1] + grid[i][col2]);
        return ret;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, m - 1, grid);
    }
};