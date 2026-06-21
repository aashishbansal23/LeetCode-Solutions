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
    void getAllNodes(TreeNode* root, vector<TreeNode*>& nodes){
        if(root == NULL){
            return ;
        }
        getAllNodes(root->left, nodes);
        nodes.push_back(root);
        getAllNodes(root->right, nodes);
    }
    
    TreeNode* getBalanceBST(vector<TreeNode*> nodes, int i, int j){
        if(i > j){
            return NULL;
        }
        int mid = i+(j-i)/2;
        TreeNode* ans = nodes[mid];
        ans->left = getBalanceBST(nodes, i, mid-1);
        ans->right = getBalanceBST(nodes, mid+1, j);
        return ans;
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        getAllNodes(root, nodes);
        return getBalanceBST(nodes, 0, nodes.size()-1);
    }
};