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
    pair<int, int> helper(TreeNode* root, int& ans){
        if(root == NULL){
            return {0, 0};
        }
        pair<int, int> leftAns = helper(root->left, ans);
        pair<int, int> rightAns = helper(root->right, ans);
        if((leftAns.first+rightAns.first+root->val)/(leftAns.second+rightAns.second+1) == root->val){
            ans++;
        }
        return {leftAns.first+rightAns.first+root->val, leftAns.second+rightAns.second+1};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        if(root == NULL){
            return ans;
        }
        helper(root, ans);
        return ans;
    }
};