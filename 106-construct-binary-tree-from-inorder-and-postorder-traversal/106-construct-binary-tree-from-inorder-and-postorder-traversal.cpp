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
    int getIndex(vector<int>& inorder, int ins, int ine, int element){
        if(ins >= ine){
            return -1;
        }
        while(ins <= ine){
            if(inorder[ins] == element){
                return ins;
            }
            ins++;
        }
        return -1;
    }
    
    TreeNode* buildTree(vector<int>& inorder, int ins, int ine, vector<int>& postorder, int posts, int poste){
        if(ins>ine || posts>poste){
            return NULL;
        }
        TreeNode* newNode = new TreeNode(postorder[poste]);
        int index = getIndex(inorder, ins, ine, postorder[poste]);
        if(index == -1){
            return newNode;
        }
        newNode->left = buildTree(inorder, ins, index-1, postorder, posts, posts+index-ins-1);
        newNode->right = buildTree(inorder, index+1, ine, postorder, posts+index-ins, poste-1);
        return newNode;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};