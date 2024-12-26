class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string minRemoveToMakeValid(string s)
    {
        deque<int> dq;
        vector<pair<char, int>> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (isalpha(s[i]))
                continue;
            if (s[i] == ')')
            {
                if (st.empty())
                    dq.push_back(i);
                else if (st.back().first == '(')
                    st.pop_back();
                else
                    dq.push_back(i);
            }
            else
                st.push_back({s[i], i});
        }
        for (auto &it : st)
        {
            dq.push_back(it.second);
        }
        string h = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (i == dq.front())
            {
                dq.pop_front();
                continue;
            }
            h += s[i];
        }
        return h;
    }
};