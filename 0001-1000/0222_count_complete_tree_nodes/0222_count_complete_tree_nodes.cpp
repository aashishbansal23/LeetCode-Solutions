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
    int getLeftDepth(TreeNode* root){
        int ans = 0;
        while(root != NULL){
            ans++;
            root = root->left;
        }
        return ans;
    }
    
    int getRightDepth(TreeNode* root){
        int ans = 0;
        while(root != NULL){
            ans++;
            root = root->right;
        }
        return ans;
    }
    
public:
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftDepth = getLeftDepth(root);
        int rightDepth = getRightDepth(root);
        if(leftDepth == rightDepth){
            return pow(2, leftDepth)-1;
        }else{
            int one = countNodes(root->left);
            int two = countNodes(root->right);
            return 1+one+two;
        }
    }
};