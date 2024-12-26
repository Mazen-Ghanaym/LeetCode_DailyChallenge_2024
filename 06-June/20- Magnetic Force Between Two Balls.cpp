class Solution
{
public:
    bool isgood(int mid, vector<int> &nums, int m)
    {
        int cnt = 0;
        int idx = 0;
        m--;
        while (m--)
        {
            auto it = lower_bound(nums.begin(), nums.end(), nums[idx] + mid);
            if (it == nums.end())
                return 0;
            idx = it - nums.begin();
        }
        return 1;
    }
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        int l = 0, r = 1e9;
        int ans = 0;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (isgood(mid, position, m))
            {
                l = mid + 1, ans = mid;
            }
            else
                r = mid - 1;
        }
        return ans;
    }
};