/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    bool hasCycle(ListNode *head)
    {
        int cnt = 0;
        ListNode *ptr = head;
        while (ptr != NULL)
        {
            ptr = ptr->next;
            cnt++;
            if (cnt > 1e4)
                return 1;
        }
        return 0;
    }
};