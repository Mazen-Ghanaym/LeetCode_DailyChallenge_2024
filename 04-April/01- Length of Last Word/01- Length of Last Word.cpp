class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int lengthOfLastWord(string s)
    {
        vector<string> vc;
        string h = "";
        for (auto &c : s)
        {
            if (c == ' ' && !h.empty())
            {
                vc.push_back(h);
                h = "";
            }
            else if (c != ' ')
                h += c;
        }
        if (!h.empty())
            vc.push_back(h);
        return vc.back().size();
    }
};