class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> mp;
        for (auto &it : strs)
        {
            string cp = it;
            sort(cp.begin(), cp.end());
            mp[cp].push_back(it);
        }
        vector<vector<string>> ans;
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};