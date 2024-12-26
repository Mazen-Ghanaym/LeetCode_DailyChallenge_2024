class Solution
{
public:
#define ll long long
#define sz(x) (int)x.size()
    int l, k;
    ll sum = 0;
    bool good(multiset<int> &ladder, multiset<int> &bricks, int diff)
    {
        if (l == 0)
        {
            sum += diff;
            if (sum > k)
                return false;
            else
                return true;
        }
        if (sz(ladder) < l)
        {
            ladder.insert(diff);
            return true;
        }
        else
        {
            auto it = ladder.begin();
            if (diff > *it)
            {
                int temp = *it;
                sum += temp;
                ladder.erase(it);
                ladder.insert(diff);
                if (sum > k)
                    return false;
                else
                    return true;
            }
            else
            {
                sum += diff;
                if (sum > k)
                    return false;
                else
                    return true;
            }
        }
        return false;
    }
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        l = ladders;
        k = bricks;
        multiset<int> ladder, brick;
        ll sum_bricks = 0;
        int cnt = 1, n = (int)heights.size();
        for (int i = 1; i < n; i++)
        {
            if (heights[i] <= heights[i - 1])
            {
                cnt++;
                continue;
            }
            ll diff = heights[i] - heights[i - 1];
            if (good(ladder, brick, diff))
                cnt++;
            else
                break;
        }
        return cnt - 1;
    }
};