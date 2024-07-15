class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        int st = 1;
        long long sum = 0;
        int n = customers.size();
        int i = 0;
        while (i < n)
        {
            if (st >= customers[i][0])
            {
                st += customers[i][1];
                sum += st - customers[i][0];
                i++;
            }
            else
                st++;
        }
        // cout<<sum<<"\n";
        return (double)sum / n;
    }
};