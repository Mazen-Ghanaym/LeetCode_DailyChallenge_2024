class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool isPowerOfTwo(int n)
    {
        if (n == 0)
            return 0;
        int lg = __lg(n);
        return (1LL << lg) == n;
    }
};