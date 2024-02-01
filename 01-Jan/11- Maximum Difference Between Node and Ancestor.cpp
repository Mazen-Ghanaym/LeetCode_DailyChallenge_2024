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
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int max_diff = -1;
    pair<int, int> maxdiff(TreeNode* root){
        if(root == NULL)return {1e9, -1e9};
        int mxv = root->val;
        int mnv = root->val;
        if(root->left != NULL){
            auto [mx, mn] = maxdiff(root->left);
            mxv = max(root->val, mx);
            mnv = min(root->val, mn);
        }
        if(root->right != NULL){
            auto [mx, mn] = maxdiff(root->right);
            mxv = max(mxv, mx);
            mnv = min(mnv, mn);
        }
        max_diff = max({max_diff, abs(mxv - root->val), abs(mnv - root->val)});
        return {mxv, mnv};
    }
    int maxAncestorDiff(TreeNode* root) {
        
        int ans = maxdiff(root).first;
        return max_diff;
    }
};