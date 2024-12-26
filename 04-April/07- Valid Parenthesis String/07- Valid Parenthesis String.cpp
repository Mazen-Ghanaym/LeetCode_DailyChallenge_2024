class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool checkValidString(string s)
    {
        int mn = 0, mx = 0;
        for (auto &c : s)
        {
            if (c == '(')
                mn++, mx++;
            else if (c == ')')
                mn--, mx--;
            else
                mn--, mx++;
            if (mx < 0)
                return 0;
            mn = max(mn, 0);
        }
        return mn == 0;
    }
};