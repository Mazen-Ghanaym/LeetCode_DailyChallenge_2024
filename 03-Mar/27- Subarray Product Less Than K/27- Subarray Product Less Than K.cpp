class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int cnt = 0;
        int l = 0, r = 0, n = nums.size();
        int prod = 1;
        while (r < n)
        {
            prod *= nums[r];
            while (prod >= k && l <= r)
            {
                prod /= nums[l++];
            }
            if (r >= l)
                cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
};