class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        for (auto &inv : intervals)
        {
            if (ans.empty())
            {
                ans.push_back(inv);
                continue;
            }
            while (!ans.empty() && ans.back().front() >= inv.front())
            {
                ans.pop_back();
            }
            bool added = 1;
            if (!ans.empty() && ans.back()[1] >= inv[0])
            {
                ans.back()[1] = max(inv[1], ans.back()[1]);
                added = 0;
            }
            if (added)
                ans.push_back(inv);
        }
        return ans;
    }
};