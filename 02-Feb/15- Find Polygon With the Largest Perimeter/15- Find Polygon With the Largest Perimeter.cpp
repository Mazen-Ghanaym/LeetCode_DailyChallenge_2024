class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long largestPerimeter(vector<int> &nums)
    {
        long long sum = 0;
        bool ok = 0;
        long long ans = 0;
        sort(nums.begin(), nums.end());
        for (auto it : nums)
        {
            if (sum > it)
            {
                ok = 1;
                ans = sum + it;
            }
            sum += it;
        }
        return (ok ? ans : -1);
    }
};