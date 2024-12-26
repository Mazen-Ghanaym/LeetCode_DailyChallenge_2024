class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minKBitFlips(vector<int> &nums, int k)
    {
        int n = nums.size();
        int operations = 0;
        int mnv = 0;
        vector<int> deleteOperation(n + 2);
        for (int i = 0; i < n; i++)
        {
            operations += deleteOperation[i];
            if (operations % 2)
                nums[i] = !nums[i];

            if (nums[i] == 0)
            {
                mnv++;
                if (i + k <= n)
                {
                    deleteOperation[i + k]--;
                    nums[i] = 1;
                    operations++;
                }
                else
                    return -1;
            }
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return (sum == n ? mnv : -1);
    }
};