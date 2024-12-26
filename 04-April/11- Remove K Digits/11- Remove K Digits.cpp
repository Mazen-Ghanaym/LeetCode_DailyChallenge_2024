class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string removeKdigits(string num, int k)
    {
        stack<char> st;
        for (auto &dig : num)
        {
            while (k > 0 && !st.empty() && st.top() > dig)
            {
                st.pop();
                k--;
            }
            st.push(dig);
        }
        while (!st.empty() && k)
        {
            st.pop();
            k--;
        }
        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        ::reverse(ans.begin(), ans.end());
        string res = "";
        bool first = 0;
        for (auto &dig : ans)
        {
            if (dig != '0')
                first = 1;
            if (first)
                res += dig;
        }
        return (res.empty() ? "0" : res);
    }
};