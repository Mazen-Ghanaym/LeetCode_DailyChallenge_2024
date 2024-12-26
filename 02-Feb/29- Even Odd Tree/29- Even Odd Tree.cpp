/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    bool isEvenOddTree(TreeNode *root)
    {
        bool ok = 1;
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            int sz = q.size();
            bool parity = !(level % 2);
            int prev = (parity ? -1 : 1e7);
            while (sz--)
            {
                TreeNode *v = q.front();
                q.pop();
                if (parity)
                {
                    if (v->val % 2 != parity || v->val <= prev)
                    {
                        // cout<<v->val << " " << prev <<" "<<parity<<"\n";
                        ok = 0;
                    }
                    prev = v->val;
                }
                else
                {
                    if (v->val % 2 != parity || v->val >= prev)
                    {
                        // cout<<v->val << " " << prev <<" "<<parity<<"\n";
                        ok = 0;
                    }
                    prev = v->val;
                }
                if (v->left)
                    q.push(v->left);
                if (v->right)
                    q.push(v->right);
            }
            level++;
        }
        return ok;
    }
};