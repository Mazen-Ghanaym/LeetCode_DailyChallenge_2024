class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> nxt(n), prv(n);
        prv[0] = height[0];
        nxt[n - 1] = height[n - 1];
        for (int i = 1; i < n - 1; i++)
        {
            prv[i] = max(prv[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            nxt[i] = max(nxt[i + 1], height[i]);
        }
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            // cout << i << " " << prv[i - 1] << " " << nxt[i + 1] << "\n";
            ans += max(0, min(prv[i - 1], nxt[i + 1]) - height[i]);
        }
        return ans;
    }
};