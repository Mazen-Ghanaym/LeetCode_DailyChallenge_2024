class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        for (auto &num : nums)
        {
            num %= k;
        }
        map<int, int> mp;
        mp[0] = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            sum %= k;
            if (mp.find(sum) != mp.end() && i + 1 - mp[sum] > 1)
                return 1;
            if (mp[sum] == 0 && sum != 0)
                mp[sum] = i + 1;
        }
        return 0;
    }
};