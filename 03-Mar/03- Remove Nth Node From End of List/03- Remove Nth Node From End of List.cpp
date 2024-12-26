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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int cnt = 0;
        ListNode *ptr = head;
        while (ptr)
        {
            cnt++;
            ptr = ptr->next;
        }
        int node = cnt - n + 1;
        if (node == 1)
            head = head->next;
        else
        {
            ListNode *prev;
            ptr = head;
            int c = 0;
            while (ptr->next)
            {
                c++;
                if (c == node)
                    break;
                prev = ptr;
                ptr = ptr->next;
            }
            prev->next = ptr->next;
        }
        return head;
    }
};