class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prev_dist(n), next_dist(n);
        stack<int> st; // increasing stack
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            prev_dist[i] = (st.empty() ? i + 1 : i - st.top()); // i + 1 == i - (-1)
            st.push(i);
        }
        st = stack<int>();
        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            next_dist[i] = (st.empty() ? n - i : st.top() - i);
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            long long val = ((arr[i] % MOD) * (prev_dist[i] % MOD)) % MOD;
            val = ((val % MOD) * (next_dist[i] % MOD)) % MOD;
            ans = ((ans % MOD) + (val % MOD)) % MOD;
        }
        return ans;
    }
};