class Solution
{
public:
#define ll long long
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n), prev(n, -1);
        map<int, int> idxs;
        for (int i = 0; i < n; i++)
            idxs[nums[i]] = i;
        int mxlen = 0, idx = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] % nums[j] == 0)
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        prev[i] = nums[j];
                        if (dp[i] > mxlen)
                        {
                            mxlen = dp[i];
                            idx = i;
                        }
                    }
                }
            }
        }
        vector<int> ans;
        while (prev[idx] != -1)
            ans.push_back(nums[idx]), idx = idxs[prev[idx]];
        ans.push_back(nums[idx]);
        return ans;
    }
};