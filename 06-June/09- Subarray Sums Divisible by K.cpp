class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int subarraysDivByK(vector<int> &nums, int k)
    {
        map<int, int> mp;
        mp[0] = 1;
        int cnt = 0;
        int sum = 0;
        for (auto &num : nums)
        {
            sum += num;
            cnt += mp[(sum % k + k) % k];
            mp[(sum % k + k) % k]++;
        }
        return cnt;
    }
};