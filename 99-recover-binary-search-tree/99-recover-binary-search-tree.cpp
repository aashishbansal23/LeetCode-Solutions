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
    
    void getLeftMax(TreeNode* root, TreeNode* & left_max_node, int& left_max_value){
        if(root == NULL){
            return ;
        }
        if(root->val > left_max_value){
            left_max_value = root->val;
            left_max_node = root;
        }
        getLeftMax(root->left, left_max_node, left_max_value);
        getLeftMax(root->right, left_max_node, left_max_value);
    }
    
    void getRightMin(TreeNode* root, TreeNode* & right_min_node, int& right_min_value){
        if(root == NULL){
            return ;
        }
        if(root->val < right_min_value){
            right_min_value = root->val;
            right_min_node = root;
        }
        getRightMin(root->left, right_min_node, right_min_value);
        getRightMin(root->right, right_min_node, right_min_value);
    }
    
    void reCreate(TreeNode* root){
        if(root == NULL){
            return ;
        }
        TreeNode* left_max_node = NULL;
        TreeNode* right_min_node = NULL;
        int left_max_value = INT_MIN;
        int right_min_value = INT_MAX;
        getLeftMax(root->left, left_max_node, left_max_value);
        getRightMin(root->right, right_min_node, right_min_value);
        if(left_max_node!=NULL && right_min_node!=NULL && left_max_node->val>root->val && right_min_node->val<root->val){
            int temp = left_max_node->val;
            left_max_node->val = right_min_node->val;
            right_min_node->val = temp;
        }else if(left_max_node!=NULL && left_max_node->val>root->val){
            int temp = root->val;
            root->val = left_max_node->val;
            left_max_node->val = temp;
        }else if(right_min_node!=NULL && right_min_node->val<root->val){
            int temp = right_min_node->val;
            right_min_node->val = root->val;
            root->val = temp;
        }
        reCreate(root->left);
        reCreate(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        // Second Try
        if(root == NULL){
            return ;
        }
        reCreate(root);
        
        
        
        // First Try
        // vector<int> store;
        // getAllValues(root, store);
        // sort(store.begin(), store.end());
        // int i = 0;
        // reCreateTree(root, store, i);
    }
};