class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int solvefor1D(vector<int> &nums, int target)
    {
        map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int cnt = 0;
        for (auto it : nums)
        {
            sum += it;
            cnt += mp[sum - target];
            mp[sum]++;
        }
        return cnt;
    }
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> nums(m);
            for (int j = i; j < n; j++)
            {
                for (int k = 0; k < m; k++)
                    nums[k] += matrix[j][k];
                ans += solvefor1D(nums, target);
            }
        }
        return ans;
    }
};