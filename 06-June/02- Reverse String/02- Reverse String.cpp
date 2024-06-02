class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    void reverseString(vector<char> &s)
    {
        ::reverse(s.begin(), s.end());
    }
};