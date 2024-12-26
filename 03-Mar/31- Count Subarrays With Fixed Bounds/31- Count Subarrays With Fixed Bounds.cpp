class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long cnt = 0;
        int n = nums.size();
        map<int, int> idx;
        int invalid = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > maxK || nums[i] < minK)
                invalid = i + 1;
            if (nums[i] == maxK)
                idx[maxK] = i + 1;
            if (nums[i] == minK)
                idx[minK] = i + 1;
            if (min(idx[maxK], idx[minK]) > invalid)
                cnt += min(idx[maxK], idx[minK]) - invalid;
        }
        return cnt;
    }
};