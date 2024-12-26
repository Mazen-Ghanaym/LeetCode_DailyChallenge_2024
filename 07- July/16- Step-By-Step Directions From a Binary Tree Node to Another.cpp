/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL), cout.tie(NULL);
    }
    map<int, array<int, 3>> adj;
    void dfs(TreeNode *root)
    {
        if (root == NULL)
            return;
        if (root->left != NULL)
        {
            adj[root->val][1] = root->left->val;
            adj[root->left->val][0] = root->val;
            dfs(root->left);
        }
        if (root->right != NULL)
        {
            adj[root->val][2] = root->right->val;
            adj[root->right->val][0] = root->val;
            dfs(root->right);
        }
    }
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        dfs(root);
        vector<pair<int, int>> par(1e5 + 2);
        par[startValue] = {-1, -1};
        queue<int> q;
        vector<int> dist(1e5 + 2, 1e5);
        q.push(startValue);
        dist[startValue] = 0;
        bool ok = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (u == destValue || ok)
                break;
            for (int i = 0; i < 3; i++)
            {
                int ch = adj[u][i];
                if (ch == 0)
                    continue;
                if (dist[u] + 1 < dist[ch])
                {
                    dist[ch] = dist[u] + 1;
                    if (i == 0)
                    {
                        par[ch] = {u, 0};
                    }
                    else if (i == 1)
                    {
                        par[ch] = {u, 1};
                    }
                    else
                        par[ch] = {u, 2};
                    q.push(ch);
                    if (ch == destValue)
                    {
                        ok = 1;
                        break;
                    }
                }
            }
        }
        string ans = "";
        auto x = par[destValue];
        while (x.first != -1)
        {
            if (x.second == 0)
                ans += 'U';
            else if (x.second == 1)
                ans += 'L';
            else
                ans += 'R';
            x = par[x.first];
        }
        ::reverse(ans.begin(), ans.end());
        return ans;
    }
};