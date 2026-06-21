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
    TreeNode* getBSTleft(vector<int>& preorder, int& i, int& size, int parent){
        if(i >= size){
            return NULL;
        }
        if(preorder[i] >= parent){
            return NULL;
        }
        TreeNode* newNode = new TreeNode(preorder[i++]);
        newNode->left = getBSTleft(preorder, i, size, newNode->val);
        newNode->right = getBSTleft(preorder, i, size, parent);
        return newNode;
    }
    
    TreeNode* getBSTright(vector<int>& preorder, int& i, int& size, int parent){
        if(i >= size){
            return NULL;
        }
        if(preorder[i] < parent){
            return NULL;
        }
        TreeNode* newNode = new TreeNode(preorder[i++]);
        newNode->left = getBSTleft(preorder, i, size, newNode->val);
        newNode->right = getBSTright(preorder, i, size, parent);
        return newNode;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int size = preorder.size();
        if(size < 1){
            return NULL;
        }
        int i = 0;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = getBSTleft(preorder, i, size, root->val);
        root->right = getBSTright(preorder, i, size, root->val);
        return root;
    }
};