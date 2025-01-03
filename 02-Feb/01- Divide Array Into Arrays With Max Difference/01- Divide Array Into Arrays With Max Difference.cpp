class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i += 3)
        {
            if (nums[i + 2] - nums[i] <= k)
                ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
            else
                return {};
        }
        return ans;
    }
};