class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int calc(vector<int> &arr)
    {
        int mxv = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int mn = arr[i];
            for (int j = i; j < n; j++)
            {
                mn = min(mn, arr[j]);
                if ((j - i + 1) * mn > mxv)
                    mxv = (j - i + 1) * mn;
            }
        }
        return mxv;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int mxv = 0;
        vector<int> arr(m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == '1')
                    arr[j]++;
                else
                    arr[j] = 0;
            mxv = max(mxv, calc(arr));
            // cout<<mxv <<"\n";
        }
        return mxv;
    }
};