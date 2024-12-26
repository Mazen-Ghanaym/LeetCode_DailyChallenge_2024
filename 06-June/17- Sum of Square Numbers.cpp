class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool judgeSquareSum(int c)
    {
        for (long long a = 0; a * a <= c; a++)
        {
            long long b = sqrt(c - a * a);
            if (b * b == c - a * a)
                return 1;
        }
        return 0;
    }
};