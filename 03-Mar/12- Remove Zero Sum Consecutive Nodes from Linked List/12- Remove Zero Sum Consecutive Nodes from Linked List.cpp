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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        vector<int> v;
        ListNode *ptr = head;
        while (ptr)
        {
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += v[j];
                if (sum == 0)
                {
                    for (int k = i; k <= j; k++)
                        v[k] = -1e5;
                    break;
                }
            }
        }
        ListNode *newhead = NULL, *tail = NULL;
        for (int i = 0; i < n; i++)
        {
            if (v[i] != -1e5)
            {
                ListNode *newnode = new ListNode(v[i]);
                if (newhead == NULL)
                {
                    newhead = tail = newnode;
                }
                else
                {
                    tail->next = newnode;
                    tail = tail->next;
                }
            }
        }
        return newhead;
    }
};