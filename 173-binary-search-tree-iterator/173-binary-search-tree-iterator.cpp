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
// First Try
// class BSTIterator {
//     stack<int> store;
    
//     void getAllValues(TreeNode* root){
//         if(root == NULL){
//             return ;
//         }
        
//         getAllValues(root->right);
//         store.push(root->val);
//         getAllValues(root->left);
//     }
    
// public:
//     BSTIterator(TreeNode* root) {
//         getAllValues(root);
//     }
    
//     int next() {
//         if(!store.empty()){
//             int ans = store.top();
//             store.pop();
//             return ans;
//         }else{
//             return -1;
//         }
//     }
    
//     bool hasNext() {
//         if(!store.empty()){
//             return true;
//         }else{
//             return false;
//         }
//     }
// };

class BSTIterator {
    stack<TreeNode*> store;
    
    void getLeftValues(TreeNode* root){
        if(root == NULL){
            return ;
        }
        store.push(root);
        getLeftValues(root->left);
    }
    
public:
    
    BSTIterator(TreeNode* root) {
        getLeftValues(root);
    }
    
    int next() {
        int ans = -1;
        if(!store.empty()){
            TreeNode* curr = store.top();
            ans = curr->val;
            store.pop();
            getLeftValues(curr->right);
        }
        return ans;
    }
    
    bool hasNext() {
        if(!store.empty()){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */