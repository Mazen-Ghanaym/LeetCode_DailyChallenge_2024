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
    int sum = 0;
    string s = "";
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    void rec(TreeNode *root)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            s += char('0' + root->val);
            sum += stoi(s);
            s.pop_back();
            return;
        }
        s += char(root->val + '0');
        rec(root->left);
        rec(root->right);
        s.pop_back();
    }
    int sumNumbers(TreeNode *root)
    {
        rec(root);
        return sum;
    }
};