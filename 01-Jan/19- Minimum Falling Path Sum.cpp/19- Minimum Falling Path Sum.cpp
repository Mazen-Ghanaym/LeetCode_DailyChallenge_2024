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
    vector<vector<int>> mat;
    int n;
    bool isValid(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    int rec(int i, int j)
    {
        if (i == n)
            return 0;
        if (!isValid(i, j))
            return 1e5;
        int &ret = dp[i][j];
        if (ret != -100000)
            return ret;
        ret = INT_MAX;
        ret = min(ret, mat[i][j] + rec(i + 1, j + 1));
        ret = min(ret, mat[i][j] + rec(i + 1, j));
        ret = min(ret, mat[i][j] + rec(i + 1, j - 1));
        return ret;
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        mat = matrix;
        n = matrix.size();
        int min_value = INT_MAX;
        dp = vector<vector<int>>(n + 3, vector<int>(n + 3, -100000));
        for (int j = 0; j < n; j++)
        {
            min_value = min(min_value, rec(0, j));
        }
        return min_value;
    }
};