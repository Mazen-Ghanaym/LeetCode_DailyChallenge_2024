class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights)
            adj[it[0]].push_back({it[1], it[2]});
        queue<pair<int, int>> q;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        q.push({src, 0});
        int level = 0;
        while (level <= k)
        {
            int cnt = q.size();
            while (cnt--)
            {
                auto [par, distance] = q.front();
                q.pop();
                // cout<<par<<"\n";
                for (auto child : adj[par])
                {
                    if (dist[par] + child.second < dist[child.first])
                    {
                        dist[child.first] = distance + child.second;
                        q.push({child.first, dist[child.first]});
                    }
                }
            }
            level++;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};