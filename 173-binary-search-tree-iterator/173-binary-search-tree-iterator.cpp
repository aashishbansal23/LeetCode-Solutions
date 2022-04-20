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
class BSTIterator {
    stack<int> store;
    
    void getAllValues(TreeNode* root){
        if(root == NULL){
            return ;
        }
        
        getAllValues(root->right);
        store.push(root->val);
        getAllValues(root->left);
    }
    
public:
    BSTIterator(TreeNode* root) {
        getAllValues(root);
    }
    
    int next() {
        if(!store.empty()){
            int ans = store.top();
            store.pop();
            return ans;
        }else{
            return -1;
        }
    }
    
    bool hasNext() {
        if(!store.empty()){
            return true;
        }else{
            return false;
        }
    }
};

// class BSTIterator {
// public:
//     BSTIterator(TreeNode* root) {
//     }
    
//     int next() {
//     }
    
//     bool hasNext() {
//     }
// };

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */