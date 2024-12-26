class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int cnt = 0;
        int prod = 1;
        for (auto &i : nums)
        {
            if (i == 0)
                cnt++;
            else
                prod *= i;
        }
        int n = nums.size();
        vector<int> ans(nums.size());
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                if (cnt == 1)
                {
                    ans[i] = prod;
                }
                else
                    ans[i] = 0;
            }
            else
            {
                if (cnt)
                    ans[i] = 0;
                else
                    ans[i] = prod / nums[i];
            }
        }
        return ans;
    }
};