class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> freq(n + 1);
        for (auto it : nums)
            freq[it]++;
        int has2, not_exist;
        for (int i = 1; i <= n; i++)
        {
            if (!freq[i])
                not_exist = i;
            if (freq[i] > 1)
                has2 = i;
        }
        return {has2, not_exist};
    }
};