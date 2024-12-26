class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> freq(26);
        for (auto &c : tasks)
            freq[c - 'A']++;
        sort(freq.begin(), freq.end());
        int mx = freq.back() - 1;
        int idle = mx * n;
        for (int i = 0; i < 25; i++)
        {
            idle -= min(mx, freq[i]);
        }
        return idle < 0 ? tasks.size() : tasks.size() + idle;
    }
};