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
    bool checkNum(TreeNode* root, int k){
        if(root == NULL){
            return false;
        }
        if(root->val == k){
            return true;
        }
        if(checkNum(root->left, k)){
            return true;
        }
        return checkNum(root->right, k);
    }
    
    bool findTargetHelp(TreeNode* root, TreeNode* temp, int k){
        if(root==NULL || temp==NULL){
            return false;
        }
        if(k-temp->val!=temp->val && checkNum(root, k-temp->val)){
            return true;
        }
        if(findTargetHelp(root, temp->left, k)){
            return true;
        }
        return findTargetHelp(root, temp->right, k);
    }
    
    void getAllElements(TreeNode* root, vector<int>& elements){
        if(root == NULL){
            return ;
        }
        getAllElements(root->left, elements);
        elements.push_back(root->val);
        getAllElements(root->right, elements);
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> elements;
        getAllElements(root, elements);
        int i=0, j=elements.size()-1;
        while(i < j){
            if(elements[i]+elements[j] == k){
                return true;
            }else if(elements[i]+elements[j] > k){
                j--;
            }else{
                i++;
            }
        }
        return false;
        
        // First Try
        // return findTargetHelp(root, root, k);
    }
};