class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int rangeBitwiseAnd(int left, int right)
    {
        int ad = 0;
        int i = left, j = right;
        while (i != j)
        {
            ad++;
            i /= 2;
            j /= 2;
        }
        return (i << ad);
    }
};