class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int ispalind(int l, int r, string &s)
    {
        int cnt = 0;
        while (l >= 0 && r < s.size())
        {
            if (s[l] == s[r])
                cnt++;
            else
                break;
            l--, r++;
        }
        return cnt;
    }
    int countSubstrings(string s)
    {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += ispalind(i, i, s);
            ans += ispalind(i, i + 1, s);
        }
        return ans;
    }
};