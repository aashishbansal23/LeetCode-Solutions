/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void check(TreeNode* root, TreeNode* p, TreeNode* q, bool& pCheck, bool& qCheck){
        if(root==NULL || (pCheck && qCheck)){
            return ;
        }
        if(root == p){
            pCheck = true;
        }
        if(root == q){
            qCheck = true;
        }
        check(root->left, p, q, pCheck, qCheck);
        check(root->right, p, q, pCheck, qCheck);
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q){
            return root;
        }
        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
        if(!leftAns){
            return rightAns;
        }else if(!rightAns){
            return leftAns;
        }else{
            return root;
        }
        
        
        
        
        // First Try
        // if(root == NULL){
        //     return root;
        // }
        // if(root==p || root==q){
        //     return root;
        // }
        // bool pCheck = false;
        // bool qCheck = false;
        // check(root->left, p, q, pCheck, qCheck);
        // if(pCheck && qCheck){
        //     return lowestCommonAncestor(root->left, p, q);
        // }else if(!pCheck && !qCheck){
        //     return lowestCommonAncestor(root->right, p, q);
        // }else{
        //     return root;
        // }
    }
};