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
    void getAllValues(TreeNode* root, vector<int>& store){
        if(root == NULL){
            return ;
        }
        getAllValues(root->left, store);
        store.push_back(root->val);
        getAllValues(root->right, store);
    }
    
    void reCreateTree(TreeNode* root, vector<int>& store, int& i){
        if(root == NULL){
            return ;
        }
        reCreateTree(root->left, store, i);
        root->val = store[i++];
        reCreateTree(root->right, store, i);
    }
    
public:
    void recoverTree(TreeNode* root) {
        vector<int> store;
        getAllValues(root, store);
        sort(store.begin(), store.end());
        int i = 0;
        reCreateTree(root, store, i);
    }
};