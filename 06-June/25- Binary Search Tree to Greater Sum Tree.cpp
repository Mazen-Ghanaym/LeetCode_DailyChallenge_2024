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
    vector<int> nums;
    void dfs(TreeNode *root)
    {
        if (root == NULL)
            return;
        nums.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    void dfs(TreeNode *root, map<int, int> &mp)
    {
        if (root == NULL)
            return;
        root->val = mp[root->val];
        dfs(root->left, mp);
        dfs(root->right, mp);
    }
    TreeNode *bstToGst(TreeNode *root)
    {
        dfs(root);
        sort(nums.begin(), nums.end());
        map<int, int> mp;
        nums.push_back(0);
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            mp[nums[i]] = nums[i] + nums[i + 1];
            nums[i] += nums[i + 1];
        }
        dfs(root, mp);
        return root;
    }
};