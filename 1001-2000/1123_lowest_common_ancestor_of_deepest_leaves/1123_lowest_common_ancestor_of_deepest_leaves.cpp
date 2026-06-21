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
    int getDepth(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return max(getDepth(root->left), getDepth(root->right))+1;
    }
    
    void getNumofDeepestNodes(TreeNode* root, int depth, int& ans){
        if(root == NULL){
            return ;
        }
        if(depth == 1){
            ans++;
            return ;
        }
        getNumofDeepestNodes(root->left, depth-1, ans);
        getNumofDeepestNodes(root->right, depth-1, ans);
    }
    
    pair<bool, int> getLCA(TreeNode* root, int numOfDeepestNodes, int depth, TreeNode*& ans){
        if(root == NULL){
            return {false, 0};
        }
        if(depth == 1){
            ans = root;
            return {true, 1};
        }
        pair<bool, int> leftAns = getLCA(root->left, numOfDeepestNodes, depth-1, ans);
        pair<bool, int> rightAns = getLCA(root->right, numOfDeepestNodes, depth-1, ans);
        if(leftAns.first && rightAns.first){
            if(leftAns.second+rightAns.second == numOfDeepestNodes){
                ans = root;
                return {false, 0};
            }
            return {true, leftAns.second+rightAns.second};
        }else if(leftAns.first){
            return leftAns;
        }else if(rightAns.first){
            return rightAns;
        }else{
            return {false, 0};
        }
    }
    
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        int depth = getDepth(root);
        int numOfDeepestNodes = 0;
        getNumofDeepestNodes(root, depth, numOfDeepestNodes);
        TreeNode* ans = NULL;
        getLCA(root, numOfDeepestNodes, depth, ans);
        return ans;
    }
};