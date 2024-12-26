class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int findMaxLength(vector<int> &nums)
    {
        for (auto &i : nums)
        {
            if (i == 0)
                i = -1;
        }
        int n = nums.size();
        int ans = 0, sum = 0;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (sum == 0)
            {
                ans = i + 1;
            }
            if (mp.count(sum))
            {
                ans = max(ans, i - mp[sum]);
            }
            if (mp.count(sum) == 0)
            {
                mp[sum] = i;
            }
        }
        return ans;
    }
};