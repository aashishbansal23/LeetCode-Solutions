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
    bool validateBST(TreeNode* root, long long minRange, long long maxRange){
        if(root == NULL){
            return true;
        }
        if(root->val<minRange || root->val>maxRange){
            return false;
        }
        if(root->val == INT_MAX){
            if(root->right != NULL){
                return false;
            }
            return (validateBST(root->left, minRange, root->val-1) && validateBST(root->right, root->val, maxRange));
        }else if(root->val == INT_MIN){
            if(root->left != NULL){
                return false;
            }
            return (validateBST(root->left, minRange, root->val) && validateBST(root->right, root->val+1, maxRange));
        }else{
            return (validateBST(root->left, minRange, root->val-1) && validateBST(root->right, root->val+1, maxRange));
        }
    }
    
public:
    bool isValidBST(TreeNode* root) {
        long long minRange = INT_MIN;
        long long maxRange = INT_MAX;
        return validateBST(root, minRange, maxRange);
    }
};