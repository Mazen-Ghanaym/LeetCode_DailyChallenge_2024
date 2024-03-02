class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> sortedSquares(vector<int> &nums)
    {
        for (auto &it : nums)
            it *= it;
        sort(nums.begin(), nums.end());
        return nums;
    }
};