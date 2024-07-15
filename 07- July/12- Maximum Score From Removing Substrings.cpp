class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        int cnta = 0, cntb = 0, mn = min(x, y), ans = 0;
        for (auto &c : s)
        {
            if (c > 'b')
            {
                ans += min(cnta, cntb) * mn;
                cnta = cntb = 0;
            }
            else if (c == 'a')
            {
                if (y > x && cntb)
                {
                    ans += y;
                    cntb--;
                }
                else
                    cnta++;
            }
            else
            {
                if (x > y && cnta)
                {
                    ans += x;
                    cnta--;
                }
                else
                    cntb++;
            }
        }
        ans += min(cnta, cntb) * mn;
        return ans;
    }
};