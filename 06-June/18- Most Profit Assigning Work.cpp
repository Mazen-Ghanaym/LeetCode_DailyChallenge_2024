class Solution
{
public:
    struct work
    {
        int df, pf;
        bool operator<(const work &o) const
        {
            if (df == o.df)
                return pf < o.pf;
            return df < o.df;
        }
    };
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int n = profit.size();
        vector<work> vc;
        for (int i = 0; i < n; i++)
        {
            vc.push_back({difficulty[i], profit[i]});
        }
        sort(vc.begin(), vc.end());
        for (int i = 0; i < n; i++)
        {
            difficulty[i] = vc[i].df;
            profit[i] = vc[i].pf;
        }
        vector<int> mxv(n);
        mxv[0] = profit[0];
        for (int i = 1; i < n; i++)
            mxv[i] = max(mxv[i - 1], profit[i]);
        int ans = 0;
        for (auto &w : worker)
        {
            auto it = upper_bound(difficulty.begin(), difficulty.end(), w);
            if (it == difficulty.begin())
                continue;
            it--;
            int idx = it - difficulty.begin();
            ans += mxv[idx];
        }
        return ans;
    }
};