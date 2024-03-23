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
    void reorderList(ListNode *head)
    {
        vector<int> v;
        ListNode *ptr = head;
        while (ptr)
        {
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        vector<int> ans;
        int n = v.size();
        for (int i = 0; i <= n / 2; i++)
        {
            ans.push_back(v[i]);
            ans.push_back(v[n - i - 1]);
        }
        if (n % 2)
            ans.pop_back();
        int i = 0;
        while (i < n)
        {
            head->val = ans[i];
            head = head->next;
            i++;
        }
    }
};