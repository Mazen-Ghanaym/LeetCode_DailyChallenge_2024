class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> vis(n + 1);
        for (auto &i : nums)
        {
            if (vis[i])
                return i;
            vis[i] = 1;
        }
        return 0;
    }
};