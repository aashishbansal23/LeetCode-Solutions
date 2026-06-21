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
    
    void helper(TreeNode* root, int& ans, int curr_height , int& max_height){
        if(!root){
            return ;
        }
        if(!root->left && !root->right){
            if(max_height == -1){
                ans = root->val;
                max_height = curr_height;
            }else if(max_height == curr_height){
                ans += root->val;
            }else if(curr_height > max_height){
                ans = root->val;
                max_height = curr_height;
            }
            return ;
        }
        helper(root->left, ans, curr_height+1, max_height);
        helper(root->right, ans, curr_height+1, max_height);
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int ans = 0;
        int curr_height = 0;
        int max_height = -1;
        helper(root, ans, curr_height, max_height);
        return ans;
        
        
        // First Try
        // if(root == NULL){
        //     return 0;
        // }
        // int height = getHeight(root);
        // int ans = 0;
        // getSum(root, height, ans);
        // return ans;
    }
};