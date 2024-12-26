class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        deque<int> dq;
        sort(deck.begin(), deck.end());
        dq.push_back(deck.back());
        deck.pop_back();
        while (!deck.empty())
        {
            dq.push_front(dq.back());
            dq.pop_back();
            dq.push_front(deck.back());
            deck.pop_back();
        }
        for (auto &it : dq)
            deck.push_back(it);
        return deck;
    }
};