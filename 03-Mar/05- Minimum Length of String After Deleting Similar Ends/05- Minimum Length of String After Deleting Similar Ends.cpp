class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minimumLength(string s)
    {
        bool run = 1;
        deque<char> dq;
        for (auto ch : s)
            dq.push_back(ch);
        while (run)
        {
            run = 0;
            char ch;
            if (dq.size() > 1 && dq.front() == dq.back())
            {
                run = 1;
                ch = dq.front();
                while (!dq.empty() && dq.front() == ch)
                    dq.pop_front();
                while (!dq.empty() && dq.back() == ch)
                    dq.pop_back();
            }
        }
        return dq.size();
    }
};