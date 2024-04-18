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
    string mn = "";
    string s = "";
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    void dfs(TreeNode *root)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            s += char(root->val + 'a');
            string h = s;
            ::reverse(h.begin(), h.end());
            if (mn.empty())
                mn = h;
            else
                mn = min(mn, h);
            s.pop_back();
            return;
        }
        s += char(root->val + 'a');
        dfs(root->left);
        dfs(root->right);
        s.pop_back();
    }
    string smallestFromLeaf(TreeNode *root)
    {
        dfs(root);
        return mn;
    }
};