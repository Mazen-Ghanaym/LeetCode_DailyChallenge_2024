class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string maximumOddBinaryNumber(string s)
    {
        sort(s.rbegin(), s.rend());
        int idx = s.size() - 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                idx = i;
        }
        swap(s[idx], s[s.size() - 1]);
        return s;
    }
};