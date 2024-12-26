class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int longestSubarray(vector<int> &nums, int limit)
    {
        int mxv = 0;
        int l = 0, r = 0, n = nums.size();
        multiset<int> st;
        while (r < n)
        {
            st.insert(nums[r]);
            while (l <= r && *st.rbegin() - *st.begin() > limit)
            {
                st.erase(st.find(nums[l]));
                l++;
            }
            mxv = max(mxv, (int)st.size());
            r++;
        }
        return mxv;
    }
};