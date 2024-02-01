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
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    vector<int> leafs;
    void dfs(TreeNode* root){
        if(root == NULL)return;
        if(root->left == NULL && root->right == NULL){
            leafs.push_back(root->val);
            return;
        }
        dfs(root->left);
        dfs(root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1, tree2;
        dfs(root1);
        tree1 = leafs;
        leafs.clear();
        dfs(root2);
        tree2 = leafs;
        return tree1 == tree2;
    }
};