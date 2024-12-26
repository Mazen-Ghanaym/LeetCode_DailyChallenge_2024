class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    unordered_map<int, vector<int>> pidx;
    unordered_map<int, vector<int>> idxs;
    void dfs(int index, vector<int> &vis, unordered_map<int, bool> &visp)
    {
        if (vis[index] == true)
            return;
        vis[index] = true;

        for (auto &prime : idxs[index])
        {
            if (visp[prime] == true)
                continue;
            visp[prime] = true;
            for (auto &idxs1 : pidx[prime])
            {
                if (vis[idxs1] == true)
                    continue;
                dfs(idxs1, vis, visp);
            }
        }
    }

    bool canTraverseAllPairs(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = nums[i];
            for (int j = 2; j * j <= nums[i]; j++)
            {
                if (temp % j == 0)
                {
                    pidx[j].push_back(i);
                    idxs[i].push_back(j);
                    while (temp % j == 0)
                        temp /= j;
                }
            }
            if (temp > 1)
            {
                pidx[temp].push_back(i);
                idxs[i].push_back(temp);
            }
        }

        vector<int> vis(nums.size(), 0);
        unordered_map<int, bool> visp;
        dfs(0, vis, visp);

        for (int i = 0; i < vis.size(); i++)
            if (vis[i] == false)
                return false;
        return true;
    }
};