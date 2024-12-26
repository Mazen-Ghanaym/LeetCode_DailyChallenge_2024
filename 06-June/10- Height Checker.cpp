class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int heightChecker(vector<int> &heights)
    {
        vector<int> ex = heights;
        sort(ex.begin(), ex.end());
        int cnt = 0;
        for (int i = 0; i < ex.size(); i++)
        {
            if (ex[i] != heights[i])
                cnt++;
        }
        return cnt;
    }
};