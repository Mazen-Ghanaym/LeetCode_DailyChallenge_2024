class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int majorityElement(vector<int> &nums)
    {
        int half = nums.size() / 2;
        unordered_map<int, int> mp;
        for (auto it : nums)
            mp[it]++;
        for (auto it : mp)
            if (it.second > half)
            {
                return it.first;
                break;
            }
        return 0;
    }
};