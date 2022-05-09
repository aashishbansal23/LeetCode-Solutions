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
class FindElements {
    TreeNode* root = NULL;
    
    void recoverTree(TreeNode* root){
        if(!root){
            return ;
        }
        if(root->left){
            root->left->val = 2*root->val+1;
        }
        if(root->right){
            root->right->val = 2*root->val+2;
        }
        recoverTree(root->left);
        recoverTree(root->right);
    }
    
    bool findNum(TreeNode* root, int target){
        if(!root){
            return false;
        }
        if(root->val == target){
            return true;
        }
        return (findNum(root->left, target) || findNum(root->right, target));
    }
    
public:
    FindElements(TreeNode* root) {
        if(root){
            root->val = 0;
            recoverTree(root);
        }
        this->root = root;
    }
    
    bool find(int target) {
        return findNum(this->root, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */