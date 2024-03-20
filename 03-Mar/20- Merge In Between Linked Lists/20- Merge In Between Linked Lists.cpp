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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        int cnt = 1;
        ListNode *ptr = list1;
        ListNode *st, *end;
        while (ptr)
        {
            if (cnt == a)
                st = ptr;
            if (cnt == b + 2)
                end = ptr;
            ptr = ptr->next;
            cnt++;
        }
        // cout<<st->val<<" "<<end->val<<"\n";
        st->next = list2;
        ListNode *tail = list2;
        while (tail->next)
            tail = tail->next;
        tail->next = end;
        return list1;
    }
};