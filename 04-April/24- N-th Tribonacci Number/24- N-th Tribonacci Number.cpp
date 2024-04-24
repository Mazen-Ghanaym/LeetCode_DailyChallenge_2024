class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int tribonacci(int n)
    {
        int t[3] = {0, 1, 1};
        if (n < 3)
            return t[n];
        int ans = 0;
        for (int i = 3; i <= n; i++)
        {
            ans = t[2] + t[1] + t[0];
            t[0] = t[1];
            t[1] = t[2];
            t[2] = ans;
        }
        return ans;
    }
};