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
    
    int genereateNewTree(TreeNode* root, int adder){
        if(root == NULL){
            return 0;
        }
        if(root->right != NULL){
            root->val += genereateNewTree(root->right, adder)-adder;
        }
        root->val += adder;
        int t = 0;
        if(root->left != NULL){
            t = genereateNewTree(root->left, root->val);
            return t;
        }
        return root->val;
    }
    
    void solve(TreeNode* root, int& sum){
        if(root == NULL){
            return ;
        }
        solve(root->right, sum);
        sum += root->val;
        root->val = sum;
        solve(root->left, sum);
    }
    
public:
    TreeNode* convertBST(TreeNode* root) {
        // Third Try
        int sum = 0;
        solve(root, sum);
        return root;
        
        
        // Second Try
        // int t = genereateNewTree(root, 0);
        // return root;
        
        // First Try
        // vector<int> temp;
        // getAllElements(root, temp);
        // return createNewTree(root, temp);
    }
};