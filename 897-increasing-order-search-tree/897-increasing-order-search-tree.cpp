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
    
    void increasingBST_helper(TreeNode* root, TreeNode* & ans){
        if(root == NULL){
            return ;
        }
        // if(ans != NULL){
        //     cout << ans->val << endl;
        // }else{
        //     cout << "NO" << endl;
        // }
        increasingBST_helper(root->right, ans);
        root->right = ans;
        ans = root;
        increasingBST_helper(root->left, ans);
        root->left = NULL;
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        // Second Try
        TreeNode* ans = NULL;
        increasingBST_helper(root, ans);
        return ans;
        
        
        // First Try
        // stack<TreeNode*> store;
        // getAllNodes(root, store);
        // return createTree(store);
    }
};