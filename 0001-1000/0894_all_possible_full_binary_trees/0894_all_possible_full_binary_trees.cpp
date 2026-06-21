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
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if((n&1) == 0){
            return {};
        }
        if(n == 1){
            TreeNode* root = new TreeNode(0);
            return {root};
        }
        vector<TreeNode*> ans;
        for(int i=1; i<=n-1; i+=2){
            vector<TreeNode*> leftAns = allPossibleFBT(i);
            vector<TreeNode*> rightAns = allPossibleFBT(n-i-1);
            for(auto left:leftAns){
                for(auto right:rightAns){
                    TreeNode* root = new TreeNode(0, left, right);
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};