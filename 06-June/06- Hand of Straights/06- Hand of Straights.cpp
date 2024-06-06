class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        int n = hand.size();
        if (n % groupSize)
            return 0;
        vector<pair<int, int>> vc;
        vc.push_back({});
        sort(hand.begin(), hand.end());
        for (auto &i : hand)
        {
            bool add = 1;
            for (auto &it : vc)
            {
                if (it.second < groupSize)
                {
                    if (it.second == 0)
                    {
                        it.first = i;
                        it.second++;
                        add = 0;
                        break;
                    }
                    else if (it.first + 1 == i)
                    {
                        it.first = i;
                        it.second++;
                        add = 0;
                        break;
                    }
                }
            }
            if (add)
            {
                vc.push_back({i, 1});
            }
            if (vc.size() * groupSize > n)
                return 0;
        }
        for (auto &it : vc)
        {
            if (it.second != groupSize)
                return 0;
        }
        return 1;
    }
};