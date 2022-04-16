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
    void getAllElements(TreeNode* root, vector<int>& temp){
        if(root == NULL){
            return ;
        }
        getAllElements(root->left, temp);
        temp.push_back(root->val);
        getAllElements(root->right, temp);
    }
    
    TreeNode* createNewTree(TreeNode* root, vector<int>& temp){
        if(root == NULL){
            return NULL;
        }
        
        int t = 0;
        for(int i=0; i<temp.size(); i++){
            if(root->val <= temp[i]){
                t += temp[i];
            }
        }
        root->val = t;
        if(root->left != NULL){
            root->left = createNewTree(root->left, temp);
        }
        if(root->right != NULL){
            root->right = createNewTree(root->right, temp);
        }
        return root;
    }
    
public:
    TreeNode* convertBST(TreeNode* root) {
        vector<int> temp;
        getAllElements(root, temp);
        return createNewTree(root, temp);
    }
};