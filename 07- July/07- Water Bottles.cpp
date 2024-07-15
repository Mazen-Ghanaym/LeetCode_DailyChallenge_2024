class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int tot = 0;
        int curr = numBottles;
        int rem = 0;
        while (curr > 0)
        {
            tot += curr;
            int tmp = curr + rem;
            curr = tmp / numExchange;
            rem = tmp % numExchange;
        }
        return tot;
    }
};