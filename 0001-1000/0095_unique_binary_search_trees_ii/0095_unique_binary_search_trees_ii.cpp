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
    vector<TreeNode*> generateTreesHelp(int s, int e){
        if(s>e || s<=0){
            return {NULL};
        }
        vector<TreeNode*> ans;
        for(int i=s; i<=e; i++){
            vector<TreeNode*> leftAns = generateTreesHelp(s, i-1);
            vector<TreeNode*> rightAns = generateTreesHelp(i+1, e);
            for(auto left:leftAns){
                for(auto right:rightAns){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        // vector<TreeNode*> ans;
        return generateTreesHelp(1, n);
        // return ans;
    }
};