class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        vector<int> in(n);
        for (auto &it : roads)
        {
            in[it[0]]++;
            in[it[1]]++;
        }
        long long ans = 0;
        sort(in.begin(), in.end());
        for (int i = 0; i < n; i++)
            ans += 1LL * in[i] * (i + 1);
        return ans;
    }
};