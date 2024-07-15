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
    void dfs(TreeNode* root, int par, map<int, vector<pair<int,int>>> &adj){
        for(auto ch : adj[par]){
            TreeNode *newnode = new TreeNode(ch.first);
            if(ch.second)
                root -> left = newnode;
            else
                root -> right = newnode;
            dfs(newnode, ch.first, adj);
        }
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, vector<pair<int,int>>> adj;
        map<int, int> in;
        for(auto &it : descriptions){
            adj[it[0]].push_back({it[1], it[2]});
            in[it[0]] = in[it[0]];
            in[it[1]]++;
        }
        int st = 0;
        for(auto &i : in){
            if(i.second == 0){
                st = i.first;
                break;
            }
        }
        TreeNode *root = new TreeNode(st);
        dfs(root, st, adj);
        return root;
    }
};