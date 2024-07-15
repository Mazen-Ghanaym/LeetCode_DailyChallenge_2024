class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> freq(1001);
        for (auto &it : nums1)
            freq[it]++;
        vector<int> ans;
        for (auto &i : nums2)
        {
            if (freq[i])
            {
                ans.push_back(i);
                freq[i]--;
            }
        }
        return ans;
    }
};
