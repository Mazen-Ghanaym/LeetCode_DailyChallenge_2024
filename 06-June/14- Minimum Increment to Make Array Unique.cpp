class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                ans += (nums[i - 1] - nums[i] + 1);
                nums[i] = nums[i - 1] + 1;
            }
        }
        // for(auto &it : nums)cout<<it<<" ";
        // cout<<"\n";
        return ans;
    }
};