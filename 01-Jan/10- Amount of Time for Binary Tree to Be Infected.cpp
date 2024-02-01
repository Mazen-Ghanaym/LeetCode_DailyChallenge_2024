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
    vector<vector<int>> adj;

    void traverse(TreeNode *par)
    {
        if (par == NULL)
            return;
        if (par->left != NULL)
        {
            adj[par->val].push_back(par->left->val);
            adj[par->left->val].push_back(par->val);
            traverse(par->left);
        }
        if (par->right != NULL)
        {
            adj[par->val].push_back(par->right->val);
            adj[par->right->val].push_back(par->val);
            traverse(par->right);
        }
    }

    int amountOfTime(TreeNode *root, int start)
    {
        adj = vector<vector<int>>(1e5 + 5);
        traverse(root);
        int mxdep = 0;
        vector<int> depth(1e5 + 2);
        vector<bool> vis(1e5 + 2);
        queue<int> q;
        q.push(start);
        depth[start] = 0;
        vis[start] = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto child : adj[node])
            {
                if (!vis[child])
                {
                    vis[child] = 1;
                    depth[child] = depth[node] + 1;
                    mxdep = max(mxdep, depth[child]);
                    q.push(child);
                }
            }
        }
        return mxdep;
    }
};