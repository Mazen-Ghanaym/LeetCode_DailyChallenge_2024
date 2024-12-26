class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool isgood(int mxday, vector<int> &nums, int m, int k)
    {
        int curr = 0;
        int vsub = 0;
        for (auto &it : nums)
        {
            if (it <= mxday)
            {
                curr++;
            }
            else
            {
                curr = 0;
            }
            if (curr == k)
            {
                vsub++;
                curr = 0;
            }
        }
        return vsub >= m;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        if (n < 1LL * m * k)
            return -1;
        int l = 0, r = 1e9;
        int ans = -1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (isgood(mid, bloomDay, m, k))
            {
                r = mid - 1;
                ans = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};