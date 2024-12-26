/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        vector<int> v;
        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }
        vector<int> crit;
        int n = v.size();
        for (int i = 1; i < n - 1; i++)
        {
            if (v[i] > v[i - 1] && v[i] > v[i + 1])
                crit.push_back(i);
            if (v[i] < v[i - 1] && v[i] < v[i + 1])
                crit.push_back(i);
        }
        if (crit.size() < 2)
            return {-1, -1};
        vector<int> ans;
        int mnv = INT_MAX;
        for (int i = 1; i < crit.size(); i++)
            mnv = min(mnv, crit[i] - crit[i - 1]);
        ans = {mnv, crit.back() - crit.front()};
        return ans;
    }
};