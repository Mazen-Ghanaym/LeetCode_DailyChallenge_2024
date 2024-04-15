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
    vector<pair<int,char>> vc;
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    void dfs(TreeNode* root, char dir){
        if(root == NULL)
            return;
        if(root -> left == NULL && root->right == NULL)
            vc.push_back({root->val, dir});
        dfs(root->left, 'l');
        dfs(root->right, 'r');
    }
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root,'t');
        int sum = 0;
        for(auto &it : vc)
            if(it.second == 'l')
                sum += it.first;
        return sum;
        
    }
};