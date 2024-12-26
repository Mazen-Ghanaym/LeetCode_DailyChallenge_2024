class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int cnt = 0;
        map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        for (auto &i : nums)
        {
            sum += i;
            cnt += mp[sum - goal];
            mp[sum]++;
        }
        return cnt;
    }
};