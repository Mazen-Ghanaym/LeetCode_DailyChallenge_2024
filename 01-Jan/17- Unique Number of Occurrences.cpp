class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool uniqueOccurrences(vector<int> &arr)
    {
        vector<int> freq(2005);
        int cnt_diff = 0; // count diffenrent numbers

        for (auto it : arr)
        {
            if (!freq[it + 1000])
                cnt_diff++;
            freq[it + 1000]++;
        }

        set<int> st;
        for (auto it : freq)
        {
            if (it)
                st.insert(it);
        }

        return st.size() == cnt_diff;
    }
};