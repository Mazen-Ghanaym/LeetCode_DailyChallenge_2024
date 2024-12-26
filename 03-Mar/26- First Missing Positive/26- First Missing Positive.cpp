class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int firstMissingPositive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int st = 1;
        for (auto &i : nums)
            if (i == st)
                st++;
        return st;
    }
};