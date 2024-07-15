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
    vector<int> vals;
    void dfs(TreeNode *root)
    {
        if (root == NULL)
            return;
        vals.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    TreeNode *balance(int l, int r)
    {
        if (l > r)
            return NULL;
        int mid = (l + r) >> 1;
        TreeNode *left = balance(l, mid - 1);
        TreeNode *right = balance(mid + 1, r);
        return new TreeNode(vals[mid], left, right);
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        dfs(root);
        sort(vals.begin(), vals.end());
        return balance(0, vals.size() - 1);
    }
};