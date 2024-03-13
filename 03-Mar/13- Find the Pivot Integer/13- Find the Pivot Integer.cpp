class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int pivotInteger(int n)
    {
        int tot = n * (n + 1) / 2;
        int curr = 0;
        for (int i = 1; i <= n; i++)
        {
            curr += i;
            if (curr == tot)
                return i;
            tot -= i;
        }
        return -1;
    }
};