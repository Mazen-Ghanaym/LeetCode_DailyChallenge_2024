class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxDepth(string s)
    {
        int mxlen = 0;
        stack<char> st;
        for (auto &c : s)
        {
            if (c == '(')
                st.push(c);
            else
            {
                if (!st.empty() && c == ')' && st.top() == '(')
                    st.pop();
            }
            mxlen = max(mxlen, (int)st.size());
        }
        return mxlen;
    }
};