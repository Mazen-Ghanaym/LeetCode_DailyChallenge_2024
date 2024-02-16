class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        map<int, int> mp;
        for (auto it : arr)
            mp[it]++;
        vector<int> vc;
        for (auto it : mp)
            vc.push_back(it.second);
        sort(vc.begin(), vc.end());
        int cnt = 0;
        for (auto &it : vc)
        {
            if (it <= k)
            {
                k -= it;
                it = 0;
            }
            cnt += (it != 0);
        }
        return cnt;
    }
};