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
    void getGoodNodesCount(TreeNode* root, int maxx, int& ans){
        if(!root){
            return ;
        }
        if(root->val >= maxx){
            ans++;
        }
        getGoodNodesCount(root->left, max(root->val,maxx), ans);
        getGoodNodesCount(root->right, max(root->val,maxx), ans);
    }
    
public:
    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int ans = 1;
        getGoodNodesCount(root->left, root->val, ans);
        getGoodNodesCount(root->right, root->val, ans);
        return ans;
    }
};