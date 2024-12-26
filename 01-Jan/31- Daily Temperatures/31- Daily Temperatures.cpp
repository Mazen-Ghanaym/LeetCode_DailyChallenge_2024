class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> st;
        int n = temperatures.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && temperatures[i] >= temperatures[st.top()])
                st.pop();
            ans[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return ans;
    }
};