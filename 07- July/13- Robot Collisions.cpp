class Solution
{
public:
    struct robot
    {
        int pos, h, init;
        char dir;
        bool operator<(const robot &other) const
        {
            return pos < other.pos;
        }
    };
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        deque<robot> dq;
        int n = positions.size();
        for (int i = 0; i < n; i++)
            dq.push_back({positions[i], healths[i], i, directions[i]});
        sort(dq.begin(), dq.end());
        stack<robot> st;
        for (int i = 0; i < n; i++)
        {
            auto it = dq.front();
            // cout<<it.pos<<" "<<it.h<<" "<<it.dir<<"\n";
            dq.pop_front();
            if (it.dir == 'L')
            {
                while (!st.empty() && st.top().dir == 'R' && st.top().h < it.h)
                {
                    st.pop();
                    it.h--;
                }
                if (!st.empty() && st.top().dir == 'R' && st.top().h >= it.h)
                {
                    if (st.top().h == it.h)
                        st.pop();
                    else
                    {
                        st.top().h--;
                    }
                }
                else
                {
                    st.push(it);
                }
            }
            else
            {
                st.push(it);
            }
        }
        vector<pair<int, int>> ans;
        while (!st.empty())
        {
            ans.push_back({st.top().init, st.top().h});
            st.pop();
        }
        sort(ans.begin(), ans.end());
        vector<int> res;
        for (auto &i : ans)
            res.push_back(i.second);
        return res;
    }
};