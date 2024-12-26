class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        deque<int> dq;
        for (auto it : tokens)
            dq.push_back(it);
        sort(dq.begin(), dq.end());
        int score = 0;
        int mx = INT_MIN;
        while (!dq.empty())
        {
            if (power >= dq.front())
            {
                power -= dq.front();
                dq.pop_front();
                score++;
            }
            else if (score)
            {
                power += dq.back();
                score--;
                dq.pop_back();
            }
            else
                break;
            mx = max(mx, score);
        }
        return max(0, mx);
    }
};