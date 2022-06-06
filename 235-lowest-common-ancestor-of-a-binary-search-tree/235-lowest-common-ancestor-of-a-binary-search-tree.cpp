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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp = root;
        while(temp != NULL){
            if(temp->val>p->val && temp->val>q->val){
                temp = temp->left;
            }else if(temp->val<p->val && temp->val<q->val){
                temp = temp->right;
            }else{
                return temp;
            }
        }
        return NULL;
        
        // First Try
        // if(root == NULL){
        //     return root;
        // }
        // if(root->val>p->val && root->val>q->val){
        //     return lowestCommonAncestor(root->left, p, q);
        // }else if(root->val<p->val && root->val<q->val){
        //     return lowestCommonAncestor(root->right, p, q);
        // }else{
        //     return root;
        // }
    }
};