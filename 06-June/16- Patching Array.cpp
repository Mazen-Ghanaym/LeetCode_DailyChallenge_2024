class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        int i = 0;
        long long need = 1;
        int cnt = 0;
        while (need <= n)
        {
            if (i < nums.size() && nums[i] <= need)
            {
                need += nums[i];
                i++;
            }
            else
            {
                need += need;
                cnt++;
            }
        }
        return cnt;
    }
};