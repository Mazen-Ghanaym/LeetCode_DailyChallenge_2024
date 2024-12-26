class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool check(string &root, string &s)
    {
        if (root.size() > s.size())
            return 0;
        for (int i = 0; i < root.size(); i++)
            if (root[i] != s[i])
                return 0;
        return 1;
    }
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        vector<string> vc;
        string h = "";
        for (auto &c : sentence)
        {
            if (c == ' ')
            {
                vc.push_back(h);
                h = "";
            }
            else
                h += c;
        }
        vc.push_back(h);
        string ans = "";
        for (auto &s : vc)
        {
            int mnl = INT_MAX;
            string valid;
            for (auto &root : dictionary)
            {
                if (check(root, s))
                {
                    if (root.size() < mnl)
                    {
                        mnl = root.size();
                        valid = root;
                    }
                }
            }
            if (mnl != INT_MAX)
            {
                s = valid;
            }
            ans += s;
            ans += ' ';
        }
        ans.pop_back();
        return ans;
    }
};