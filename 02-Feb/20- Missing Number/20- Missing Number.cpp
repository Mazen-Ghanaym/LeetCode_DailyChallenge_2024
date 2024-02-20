class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0;
        for (auto it : nums)
        {
            if (it == i)
                i++;
            else
                break;
        }
        return i;
    }
};