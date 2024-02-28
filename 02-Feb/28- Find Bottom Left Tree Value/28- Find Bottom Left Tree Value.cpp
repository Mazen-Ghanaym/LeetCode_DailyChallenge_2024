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
    int treedepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return max(treedepth(root->left), treedepth(root->right)) + 1;
    }
    int leftmost, depp;
    bool ok = 1;
    void dfs(TreeNode *root, int dep = 0)
    {
        if (root == NULL)
            return;
        if (dep == depp)
        {
            leftmost = root->val;
            ok = 0;
            return;
        }
        if (ok)
        {
            dfs(root->left, dep + 1);
        }
        if (ok)
            dfs(root->right, dep + 1);
    }
    int findBottomLeftValue(TreeNode *root)
    {
        depp = treedepth(root) - 1;
        // cout<<depth<<"\n";
        dfs(root);
        return leftmost;
    }
};