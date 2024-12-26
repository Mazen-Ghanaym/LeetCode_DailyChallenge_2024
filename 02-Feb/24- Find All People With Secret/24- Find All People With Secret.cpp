class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    void dfs(int node, vector<bool> &vis, unordered_map<int, vector<int>> &adj, vector<bool> &know)
    {
        vis[node] = 1;
        for (auto child : adj[node])
        {
            know[child] = know[child] | know[node];
            if (!vis[child])
            {
                dfs(child, vis, adj, know);
            }
        }
    }
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        vector<bool> know(n);
        map<int, vector<pair<int, int>>> meets;
        for (auto it : meetings)
        {
            meets[it[2]].push_back({it[0], it[1]});
        }
        know[firstPerson] = 1;
        know[0] = 1;
        for (auto it : meets)
        {
            unordered_map<int, vector<int>> adj;
            set<int> nodes;
            for (auto [x, y] : it.second)
            {
                adj[x].push_back(y);
                adj[y].push_back(x);
                nodes.insert(x);
                nodes.insert(y);
            }
            vector<bool> vis(n + 1);
            for (auto node : nodes)
            {
                if (know[node])
                    dfs(node, vis, adj, know);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (know[i])
                ans.push_back(i);
        }
        return ans;
    }
};