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
    void getAllNodes(TreeNode* root, stack<TreeNode*>& store){
        if(root == NULL){
            return ;
        }
        getAllNodes(root->right, store);
        store.push(root);
        getAllNodes(root->left, store);
    }
    
    TreeNode* createTree(stack<TreeNode*>& store){
        if(store.empty()){
            return NULL;
        }
        TreeNode* root = store.top();
        store.pop();
        TreeNode* temp = root;
        while(!store.empty()){
            TreeNode* t = store.top();
            store.pop();
            temp->right = t;
            temp->left = NULL;
            temp = t;
        }
        temp->right = NULL;
        temp->left = NULL;
        return root;
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> store;
        getAllNodes(root, store);
        return createTree(store);
    }
};