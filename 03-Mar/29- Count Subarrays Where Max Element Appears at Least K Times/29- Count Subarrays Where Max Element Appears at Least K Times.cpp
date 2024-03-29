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
    long long countSubarrays(vector<int> &nums, int k)
    {
        map<ll, ll> mp;
        ll ans = 0;
        int l = 0, r = 0, n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int old = 0;
        while (r < n)
        {
            mp[nums[r]]++;
            old = ans;
            while (l <= r && mp[mx] >= k)
            {
                mp[nums[l]]--;
                l++;
            }
            ans += l;
            r++;
        }
        return ans;
    }
};