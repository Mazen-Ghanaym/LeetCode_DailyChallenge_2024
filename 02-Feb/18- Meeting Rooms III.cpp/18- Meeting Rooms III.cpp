class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> meeting;
        vector<long long> rooms(n);
        vector<int> freq(n);
        for (auto meet : meetings)
            meeting.push({meet[0], meet[1]});
        while (!meeting.empty())
        {
            auto [start, end] = meeting.top();
            meeting.pop();
            long long mn = 1e15, idx = -1;
            bool added = 0;
            for (int i = 0; i < n; i++)
            {
                if (rooms[i] <= start)
                {
                    added = 1;
                    rooms[i] = end;
                    freq[i]++;
                    break;
                }
                if (rooms[i] < mn)
                {
                    mn = rooms[i];
                    idx = i;
                }
            }
            if (!added)
            {
                rooms[idx] = end + mn - start;
                freq[idx]++;
            }
        }
        int mx = 0, idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (freq[i] > mx)
            {
                mx = freq[i];
                idx = i;
            }
        }
        return idx;
    }
};