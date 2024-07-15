class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int findCenter(vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(1e5 + 1);
        for (auto &it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for (int i = 1; i <= 1e5; i++)
        {
            if (adj[i].size() > 1)
                return i;
        }
        return 0;
    }
};