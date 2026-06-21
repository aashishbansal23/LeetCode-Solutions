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
    TreeNode* delNodesHelp(TreeNode* root, set<int>& to_del, vector<TreeNode*>& ans){
        if(!root){
            return NULL;
        }
        TreeNode* leftAns = delNodesHelp(root->left, to_del, ans);
        TreeNode* rightAns = delNodesHelp(root->right, to_del, ans);
        if(to_del.count(root->val) > 0){
            if(leftAns){
                ans.push_back(leftAns);
            }
            if(rightAns){
                ans.push_back(rightAns);
            }
            return NULL;
        }else{
            root->left = leftAns;
            root->right = rightAns;
            return root;
        }
    }
    
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root){
            return {};
        }
        vector<TreeNode*> ans;
        set<int> to_del;
        for(auto i:to_delete){
            to_del.insert(i);
        }
        delNodesHelp(root, to_del, ans);
        if(to_del.count(root->val) == 0){
            ans.push_back(root);
        }
        return ans;
    }
};