class Solution
{
public:
    int passThePillow(int n, int time)
    {
        int r = ceil((double)time / (n - 1));
        int ret = time % (n - 1);
        if (ret == 0)
            ret = n - 1;
        if (r % 2)
        {
            return 1 + ret;
        }
        else
        {
            return n - ret;
        }
        return 0;
    }
};