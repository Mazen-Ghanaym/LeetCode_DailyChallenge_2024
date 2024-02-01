class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (auto tok : tokens)
        {
            if (tok == "+")
            {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                st.push(val1 + val2);
            }
            else if (tok == "-")
            {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                st.push(val2 - val1);
            }
            else if (tok == "*")
            {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                st.push(val1 * val2);
            }
            else if (tok == "/")
            {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                st.push(val2 / val1);
            }
            else
            {
                int val = stoi(tok);
                st.push(val);
            }
        }
        return st.top();
    }
};