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
    
    TreeNode* buildTreeHelp(vector<int>& preorder, int pres, int pree, vector<int>& inorder, int ins, int ine){
        if(pres>pree || ins>ine){
            return NULL;
        }
        TreeNode* newNode = new TreeNode(preorder[pres]);
        int index = getIndex(inorder, ins, ine, preorder[pres]);
        if(index == -1){
            return newNode;
        }
        newNode->left = buildTreeHelp(preorder, pres+1, pres+index-ins, inorder, ins, index-1);
        newNode->right = buildTreeHelp(preorder, pres+index-ins+1, pree, inorder, index+1, ine);
        return newNode;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelp(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};