class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string makeGood(string s)
    {
        stack<char> st;
        for (auto &c : s)
        {
            if (st.empty())
            {
                st.push(c);
                continue;
            }
            if (c != st.top() && tolower(c) == tolower(st.top()))
            {
                st.pop();
            }
            else
                st.push(c);
        }
        string h = "";
        while (!st.empty())
        {
            h += st.top();
            st.pop();
        }
        ::reverse(h.begin(), h.end());
        return h;
    }
};