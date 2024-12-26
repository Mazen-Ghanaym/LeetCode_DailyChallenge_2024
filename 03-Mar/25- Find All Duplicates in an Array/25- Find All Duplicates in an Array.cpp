class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> findDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> freq(n + 1);
        for (auto &it : nums)
            freq[it]++;
        vector<int> ans;
        for (int i = 1; i <= n; i++)
            if (freq[i] == 2)
                ans.push_back(i);
        return ans;
    }
};