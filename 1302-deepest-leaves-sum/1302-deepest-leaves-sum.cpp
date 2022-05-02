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
    int getHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return max(getHeight(root->left), getHeight(root->right))+1;
    }
    
    void getSum(TreeNode* root, int height, int& ans){
        if(root == NULL){
            return ;
        }
        if(height == 1){
            ans += root->val;
            return ;
        }
        getSum(root->left, height-1, ans);
        getSum(root->right, height-1, ans);
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int height = getHeight(root);
        int ans = 0;
        getSum(root, height, ans);
        return ans;
    }
};