class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int longestPalindrome(string s)
    {
        int cnt = 0;
        map<char, int> mp;
        for (auto &c : s)
            mp[c]++;
        bool odd = 0;
        for (auto &it : mp)
        {
            cnt += (it.second / 2) * 2;
            odd |= (it.second % 2);
        }
        return cnt + odd;
    }
};