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
    void getSum(TreeNode* root, bool parent, bool grandParent, int& ans){
        if(root == NULL){
            return ;
        }
        if(grandParent){
            ans += root->val;
        }
        getSum(root->left, (root->val&1)==0, parent, ans);
        getSum(root->right, (root->val&1)==0, parent, ans);
    }
    
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(!root || (!root->left && !root->right)){
            return 0;
        }
        int ans = 0;
        getSum(root, false, false, ans);
        return ans;
    }
};