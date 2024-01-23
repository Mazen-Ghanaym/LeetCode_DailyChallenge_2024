class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxLength(vector<string> &arr)
    {
        int n = arr.size();
        int mx_len = 0;
        for (int i = 0; i < (1 << n); i++)
        {
            string s = "";
            bool work = 1;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                    s += arr[j];
                if (s.size() > 26)
                {
                    work = 0;
                    break;
                }
            }

            if (work)
            {
                set<char> st;
                for (auto c : s)
                    st.insert(c);
                if (st.size() == s.size())
                    mx_len = max(mx_len, (int)s.size());
            }
        }
        return mx_len;
    }
};