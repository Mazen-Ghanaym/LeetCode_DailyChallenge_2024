class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<vector<int>> dp;
    int n, m;
    int rec(int i, int j, string &s, string &t)
    {
        if (i == n || j == m)
            return 0;
        int &ret = dp[i][j];
        if (~ret)
            return ret;
        if (s[i] == t[j])
        {
            ret = rec(i + 1, j + 1, s, t) + 1;
        }
        else
        {
            ret = max(rec(i + 1, j, s, t), rec(i, j + 1, s, t));
        }
        return ret;
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        n = text1.size();
        m = text2.size();
        dp = vector<vector<int>>(n + 3, vector<int>(m + 3, -1));
        return rec(0, 0, text1, text2);
    }
};