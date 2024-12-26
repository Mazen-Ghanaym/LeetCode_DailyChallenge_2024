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
    int count;
    Solution()
    {
        count = 0;
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool check(vector<int> &freq)
    {
        int cnt = 0;
        for (auto it : freq)
            cnt += it % 2;
        return cnt <= 1;
    }
    void rec(TreeNode *root, vector<int> freq)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            freq[root->val]++;
            if (check(freq))
                count++;
        }
        freq[root->val]++;
        rec(root->left, freq);
        rec(root->right, freq);
    }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        vector<int> freq(10);
        rec(root, freq);
        return count;
    }
};