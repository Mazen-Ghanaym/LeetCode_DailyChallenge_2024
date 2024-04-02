class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool isIsomorphic(string s, string t)
    {
        map<char, char> mp;
        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] == 0)
            {
                mp[s[i]] = t[i];
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] != t[i])
                return 0;
        }
        set<char> st;
        int cnt = 0;
        for (auto &it : mp)
        {
            if (it.second != 0)
            {
                st.insert(it.second);
                cnt++;
            }
        }
        return st.size() == cnt;
    }
};