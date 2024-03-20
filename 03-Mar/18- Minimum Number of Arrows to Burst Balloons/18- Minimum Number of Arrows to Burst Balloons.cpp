class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int findMinArrowShots(vector<vector<int>> &points)
    {
        vector<pair<int, int>> vc;
        for (auto &it : points)
            vc.push_back({it[0], it[1]});
        sort(vc.begin(), vc.end(), [](pair<int, int> &a, pair<int, int> &b)
             { return a.second < b.second; });
        int last = vc.front().second;
        int cnt = 1;
        int n = vc.size();
        for (int i = 1; i < n; i++)
        {
            if (vc[i].first > last)
            {
                cnt++;
                last = vc[i].second;
            }
        }
        return cnt;
    }
};