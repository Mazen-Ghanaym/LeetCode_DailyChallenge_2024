class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int ans = 0, n = customers.size();
        vector<int> pref(n);
        for (int i = 0; i < n; i++)
        {
            if (grumpy[i] == 0)
            {
                ans += customers[i];
            }
            else
            {
                pref[i] = customers[i];
            }
            if (i)
                pref[i] += pref[i - 1];
        }
        // for (int i = 0; i < n; i++)
        //     cout << pref[i] << " ";
        // cout << "\n";
        auto get = [&](int l, int r) -> int
        {
            if (l == 0)
                return pref[r];
            else
                return pref[r] - pref[l - 1];
        };
        minutes--;
        int mxv = 0;
        for (int i = minutes; i < n; i++)
        {
            // cout<<get(i, i - minutes)<<"\n";
            mxv = max(mxv, get(i - minutes, i));
        }
        // cout << ans << " " << mxv << "\n";
        return ans + mxv;
    }
};