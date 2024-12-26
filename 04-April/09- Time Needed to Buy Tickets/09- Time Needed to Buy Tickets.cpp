class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int val = tickets[k];
        int sum = 0;
        for (auto &it : tickets)
            sum += min(it, val);
        for (int i = k + 1; i < tickets.size(); i++)
            sum -= (tickets[i] >= val);
        return sum;
    }
};