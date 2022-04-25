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
    void getList(TreeNode* root, TreeNode*& ans){
        if(root == NULL){
            return ;
        }
        
        getList(root->right, ans);
        getList(root->left, ans);
        root->right = ans;
        root->left = NULL;
        ans = root;
    }
    
public:
    void flatten(TreeNode* root) {
        TreeNode* ans = NULL;
        getList(root, ans);
    }
};