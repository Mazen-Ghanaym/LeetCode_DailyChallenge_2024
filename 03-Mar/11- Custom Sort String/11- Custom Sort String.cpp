class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string customSortString(string order, string s)
    {
        vector<int> freq(26);
        for (auto &ch : s)
            freq[ch - 'a']++;
        string ans = "";
        for (auto &c : order)
        {
            while (freq[c - 'a']--)
                ans += c;
        }
        for (int i = 0; i < 26; i++)
        {
            while (freq[i] > 0)
                ans += char(i + 'a'), freq[i]--;
        }
        return ans;
    }
};