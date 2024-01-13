class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minSteps(string s, string t)
    {
        int cnt = 0;
        vector<int> freqs(26), freqt(26);
        for (auto &c : s)
            freqs[c - 'a']++;
        for (auto &c : t)
            freqt[c - 'a']++;
        for (int i = 0; i < 26; i++)
        {
            cnt += max(freqs[i] - freqt[i], 0);
        }
        return cnt;
    }
};