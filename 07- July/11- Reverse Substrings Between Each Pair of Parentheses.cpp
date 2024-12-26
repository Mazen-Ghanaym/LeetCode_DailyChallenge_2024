class Solution
{
public:
    string reverseParentheses(string s)
    {
        vector<string> vc;
        vc.push_back("");
        for (auto &c : s)
        {
            if (c == '(')
                vc.push_back("");
            else if (c == ')')
            {
                string s = vc.back();
                vc.pop_back();
                ::reverse(s.begin(), s.end());
                vc.back() += s;
            }
            else
                vc.back() += c;
        }
        return vc.back();
    }
};