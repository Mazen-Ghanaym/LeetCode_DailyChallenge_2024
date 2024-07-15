class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<vector<int>> ans;
    void dfs(int node, int p, vector<vector<int>> &adj, vector<bool> &vis)
    {
        if (node != p)
            ans[node].push_back(p);
        vis[node] = 1;
        for (auto &ch : adj[node])
        {
            if (!vis[ch])
                dfs(ch, p, adj, vis);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        ans.resize(n);
        vector<vector<int>> adj(n);
        for (auto &it : edges)
        {
            adj[it[0]].push_back(it[1]);
        }
        for (int i = 0; i < n; i++)
        {
            vector<bool> vis(n);
            dfs(i, i, adj, vis);
        }
        return ans;
    }
};