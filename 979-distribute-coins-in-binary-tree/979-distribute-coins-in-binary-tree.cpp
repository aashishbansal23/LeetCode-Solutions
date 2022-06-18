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
    void distributeCoinsHelp(TreeNode* root, TreeNode* parent, int& ans){
        if(root == NULL){
            return ;
        }
        distributeCoinsHelp(root->left, root, ans);
        distributeCoinsHelp(root->right, root, ans);
        if(root->val > 1){
            parent->val += root->val-1;
            ans += root->val-1;
            root->val = 1;
        }else if(root->val < 1){
            int requiredCoins = 1+abs(root->val);
            root->val = 1;
            parent->val -= requiredCoins;
            ans += requiredCoins;
        }
    }
    
public:
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        distributeCoinsHelp(root, NULL, ans);
        return ans;
    }
};