class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        vector<pair<int, int>> vc;
        int n = profits.size();
        for (int i = 0; i < n; i++)
        {
            vc.push_back({capital[i], profits[i]});
        }
        sort(vc.begin(), vc.end());
        priority_queue<int> pq;
        int j = 0;
        for (int i = 0; i < k; i++)
        {
            while (j < n && w >= vc[j].first)
            {
                pq.push(vc[j].second);
                j++;
            }
            if (pq.empty())
                break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};