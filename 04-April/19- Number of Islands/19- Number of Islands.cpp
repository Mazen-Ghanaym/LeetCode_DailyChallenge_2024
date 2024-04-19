class Solution
{
public:
    vector<vector<bool>> vis;
    bool isvalid(int i, int j, int n, int m, vector<vector<char>> &grid)
    {
        return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1' && !vis[i][j];
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        if (!isvalid(i, j, grid.size(), grid[0].size(), grid))
            return;
        // cout<<"h: "<<i << " " << j <<"\n";
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++)
            dfs(i + dx[k], j + dy[k], grid);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    // cout<<i << " " << j << "\n";
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};