class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int firstUniqChar(string s)
    {
        vector<int> freq(26);
        for (auto c : s)
            freq[c - 'a']++;
        int n = s.size();
        int ans = -1;
        for (int i = 0; i < n; i++)
            if (freq[s[i] - 'a'] == 1)
            {
                ans = i;
                break;
            }
        return ans;
    }
};