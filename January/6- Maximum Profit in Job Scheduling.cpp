class Solution {
public:
    #define ll long long
    struct node
    {
        int l, r, price;
        bool operator<(const node &n) const
        {
            if(r==n.r)
                return l < n.l;
            return r < n.r;
        }
    };

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<node> v(n);
        for (int i = 0; i < n; ++i)
            v[i].l = startTime[i],v[i].r=endTime[i],v[i].price=profit[i];
        sort(v.begin(), v.end());
        map<ll, ll> dp;
        dp[0] = 0;
        ll sum = 0;
        for (int i = 0; i < n; ++i)
        {
            auto it = dp.upper_bound(v[i].l);
            --it;
            sum = max(sum, it->second + v[i].price);
            dp[v[i].r] = sum;
        }
        return sum;
    }
};