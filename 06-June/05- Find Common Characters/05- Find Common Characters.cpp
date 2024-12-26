class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<string> commonChars(vector<string> &words)
    {
        vector<string> ans;
        vector<int> freq(26, INT_MAX);
        for (auto &s : words)
        {
            vector<int> fq(26);
            for (auto &c : s)
                fq[c - 'a']++;
            for (int i = 0; i < 26; i++)
                freq[i] = min(freq[i], fq[i]);
        }
        for (int i = 0; i < 26; i++)
        {
            while (freq[i]--)
                ans.push_back(string(1, char(i + 'a')));
        }
        return ans;
    }
};