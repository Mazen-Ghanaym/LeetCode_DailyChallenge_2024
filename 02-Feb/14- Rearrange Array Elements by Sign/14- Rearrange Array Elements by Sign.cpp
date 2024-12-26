class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> pos, neg;
        for (auto it : nums)
            if (it > 0)
                pos.push_back(it);
            else
                neg.push_back(it);
        vector<int> ans;
        int n = pos.size();
        for (int i = 0; i < n; i++)
        {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};