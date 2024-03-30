class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int count_good(vector<int> &nums, int k)
    {
        int cnt = 0;
        map<int, int> mp;
        int n = nums.size();
        int l = 0, r = 0;
        while (r < n)
        {
            mp[nums[r]]++;
            while (l <= r && mp.size() > k)
            {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return count_good(nums, k) - count_good(nums, k - 1);
    }
};