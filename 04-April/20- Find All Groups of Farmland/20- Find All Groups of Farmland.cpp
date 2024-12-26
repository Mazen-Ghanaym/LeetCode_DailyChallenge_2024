class Solution
{
public:
    vector<vector<bool>> vis;
    bool isvalid(int i, int j, int n, int m, vector<vector<int>> &grid)
    {
        return i >= 0 && i < n && j >= 0 && j < m && grid[i][j];
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int r1, c1;
    void dfs(int i, int j, int n, int m, vector<vector<int>> &grid)
    {
        if (!isvalid(i, j, n, m, grid) || vis[i][j])
            return;
        if (!isvalid(i + 1, j, n, m, grid) && !isvalid(i, j + 1, n, m, grid))
        {
            vis[i][j] = 1;
            r1 = i, c1 = j;
            return;
        }
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++)
            dfs(i + dx[k], j + dy[k], n, m, grid);
    }
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        int n = land.size(), m = land[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m, 0));
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && land[i][j])
                {
                    dfs(i, j, n, m, land);
                    ans.push_back({i, j, r1, c1});
                }
            }
        }
        return ans;
    }
};