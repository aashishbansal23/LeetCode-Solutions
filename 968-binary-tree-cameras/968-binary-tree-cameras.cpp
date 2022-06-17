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
    void dfs(TreeNode* root, TreeNode* parent, set<TreeNode*>& visited, int& ans){
        if(root == NULL){
            return ;
        }
        dfs(root->left, root, visited, ans);
        dfs(root->right, root, visited, ans);
        if(parent==NULL && visited.count(root)==0 || visited.count(root->left)==0 || visited.count(root->right)==0){
            ans++;
            visited.insert(parent);
            visited.insert(root);
            visited.insert(root->left);
            visited.insert(root->right);
        }
    }
    
public:
    int minCameraCover(TreeNode* root) {
        int ans = 0;
        set<TreeNode*> visited;
        visited.insert(NULL);
        dfs(root, NULL, visited, ans);
        return ans;
    }
};