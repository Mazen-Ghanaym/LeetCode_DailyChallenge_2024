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
    void dfs(TreeNode *root, int depth, int dep, int val)
    {
        if (root == NULL)
            return;
        if (dep == depth - 1)
        {
            TreeNode *leftnode = new TreeNode(val, root->left, NULL);
            TreeNode *rightnode = new TreeNode(val, NULL, root->right);
            root->left = leftnode;
            root->right = rightnode;
            return;
        }
        dfs(root->left, depth, dep + 1, val);
        dfs(root->right, depth, dep + 1, val);
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *nroot = new TreeNode(val, root, NULL);
            return nroot;
        }
        dfs(root, depth, 1, val);
        return root;
    }
};