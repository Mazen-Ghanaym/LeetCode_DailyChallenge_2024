class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool rec(int node, int dest, vector<vector<int>> &adj, vector<bool> &vis)
    {
        if (node == dest)
            return 1;
        vis[node] = 1;
        int ans = 0;
        for (auto &child : adj[node])
        {
            if (!vis[child])
                ans |= rec(child, dest, adj, vis);
        }
        return ans;
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> adj(n);
        for (auto &it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n);
        return rec(source, destination, adj, vis);
    }
};