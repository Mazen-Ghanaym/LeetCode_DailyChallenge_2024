class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int scoreOfString(string s)
    {
        int score = 0;
        int n = s.size();
        for (int i = 0; i < n - 1; i++)
            score += abs(s[i] - s[i + 1]);
        return score;
    }
};