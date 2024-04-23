class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<int> ans;
        vector<int> indeg(n + 1);
        vector<vector<int>> adj(n + 1);
        for (auto &it : edges)
        {
            indeg[it[0]]++;
            indeg[it[1]]++;
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indeg[i] <= 1)
                q.push(i);
        }
        int rem = n;
        while (rem > 2)
        {
            int sz = q.size();
            while (sz--)
            {
                int u = q.front();
                rem--;
                q.pop();
                for (auto v : adj[u])
                {
                    indeg[v]--;
                    if (indeg[v] == 1)
                        q.push(v);
                }
            }
        }
        while (!q.empty())
            ans.push_back(q.front()), q.pop();
        return ans;
    }
};