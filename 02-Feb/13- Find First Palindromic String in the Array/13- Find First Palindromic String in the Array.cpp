class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool ispalind(string &s)
    {
        string t = s;
        ::reverse(t.begin(), t.end());
        return t == s;
    }
    string firstPalindrome(vector<string> &words)
    {
        for (auto &s : words)
            if (ispalind(s))
                return s;
        return "";
    }
};