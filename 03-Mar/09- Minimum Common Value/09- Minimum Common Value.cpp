class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> mp;
        for (auto &it : nums1)
            if (mp[it] == 0)
                mp[it] = 1;
        for (auto &it : nums2)
            if (mp[it] == 1)
                mp[it] = 2;
        for (auto &it : mp)
        {
            if (it.second == 2)
                return it.first;
        }
        return -1;
    }
};