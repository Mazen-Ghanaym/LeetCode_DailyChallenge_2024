class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size(), m = board[0].size();

        auto isvalid = [&](int i, int j)
        {
            return i >= 0 && i < n && j >= 0 && j < m;
        };
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        function<bool(int, int, int)> DFS = [&](int i, int j, int k) -> bool
        {
            if (k == word.size())
                return 1;
            if (!isvalid(i, j) || board[i][j] == '0' || board[i][j] != word[k])
                return 0;
            char tmp = board[i][j];
            board[i][j] = '0';
            for (int l = 0; l < 4; l++)
            {
                if (DFS(i + dx[l], j + dy[l], k + 1))
                    return 1;
            }
            board[i][j] = tmp;
            return 0;
        };
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (DFS(i, j, 0))
                    return 1;
            }
        }
        return 0;
    }
};