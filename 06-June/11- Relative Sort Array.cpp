class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> freq(1001);
        for (auto &i : arr1)
            freq[i]++;
        vector<int> ans;
        for (auto &i : arr2)
        {
            while (freq[i]--)
            {
                ans.push_back(i);
            }
        }
        for (int i = 0; i <= 1000; i++)
        {
            if (freq[i] <= 0)
                continue;
            while (freq[i]--)
                ans.push_back(i);
        }
        return ans;
    }
};