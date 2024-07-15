class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        map<int, int> mp;
        mp[0] = 1;
        int ans = 0, pref = 0;
        for (auto &i : nums)
        {
            pref += (i % 2);
            if (pref >= k)
            {
                ans += mp[pref - k];
            }
            mp[pref]++;
        }
        return ans;
    }
};