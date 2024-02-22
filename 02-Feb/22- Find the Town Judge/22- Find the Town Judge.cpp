class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> votes(n + 1);
        for (auto it : trust)
        {
            votes[it[1]]++;
            votes[it[0]]--;
        }

        for (int i = 1; i <= n; i++)
        {
            if (votes[i] == n - 1)
                return i;
        }
        return -1;
    }
};