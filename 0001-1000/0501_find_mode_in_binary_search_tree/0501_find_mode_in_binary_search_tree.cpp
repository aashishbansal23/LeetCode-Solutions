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
    vector<int> ans;
    int maxx = 0;
    int count = 0;
    int pre = NULL;
    
    void findModeHelp(TreeNode* root){
        if(root == NULL){
            return ;
        }
        findModeHelp(root->left);
        if(pre == root->val){
            count++;
        }else{
            count = 1;
        }
        if(count > maxx){
            maxx = count;
            ans.clear();
            ans.push_back(root->val);
        }else if(count == maxx){
            ans.push_back(root->val);
        }
        pre = root->val;
        findModeHelp(root->right);
    }
    
public:
    vector<int> findMode(TreeNode* root) {
        findModeHelp(root);
        return ans;
    }
};