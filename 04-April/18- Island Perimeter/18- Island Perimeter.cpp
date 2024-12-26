class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        bool one = 0;
        for (int i = 0; i < n; i++)
        {
            one = 0;
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                    one = 1;
                if (!grid[i][j] && one)
                    ans += 2, one = 0;
            }
            if (one)
                ans += 2;
        }

        one = 0;
        // cout << ans << "\n";
        for (int i = 0; i < m; i++)
        {
            one = 0;
            for (int j = 0; j < n; j++)
            {
                if (grid[j][i])
                    one = 1;
                if (!grid[j][i] && one)
                    ans += 2, one = 0;
            }
            if (one)
                ans += 2;
            // cout << ans << "\n";
        }

        return ans;
    }
};