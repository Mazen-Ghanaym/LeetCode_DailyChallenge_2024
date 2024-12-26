class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxFrequencyElements(vector<int> &nums)
    {
        vector<int> freq(101);
        for (auto it : nums)
            freq[it]++;
        int mx = *max_element(freq.begin(), freq.end());
        int cnt = 0;
        for (auto it : freq)
        {
            if (it == mx)
                cnt++;
        }
        return cnt * mx;
    }
};