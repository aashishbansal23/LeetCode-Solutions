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
    int getIndex(vector<int>& arr, int target){
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == target){
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* constructFromPrePostHelp(vector<int>& preorder, vector<int>& postorder, int& preIndex, int& postIndex){
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        if(root->val != postorder[postIndex]){
            root->left = constructFromPrePostHelp(preorder, postorder, preIndex, postIndex);
        }
        if(root->val != postorder[postIndex]){
            root->right = constructFromPrePostHelp(preorder, postorder, preIndex, postIndex);
        }
        postIndex++;
        return root;
    }
    
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preIndex = 0;
        int postIndex = 0;
        return constructFromPrePostHelp(preorder, postorder, preIndex, postIndex);
        
        
        
        
        // First Try
        // unordered_set<int> visited;
        // queue<TreeNode*> q;
        // TreeNode* root = new TreeNode(preorder[0]);
        // q.push(root);
        // visited.insert(preorder[0]);
        // while(!q.empty()){
        //     TreeNode* frontNode = q.front();
        //     q.pop();
        //     int index = getIndex(preorder, frontNode->val);
        //     if(index+1<preorder.size() && visited.count(preorder[index+1])==0){
        //         TreeNode* left = new TreeNode(preorder[index+1]);
        //         frontNode->left = left;
        //         visited.insert(preorder[index+1]);
        //         q.push(left);
        //     }
        //     index = getIndex(postorder, frontNode->val);
        //     if(index>0 && visited.count(postorder[index-1])==0){
        //         TreeNode* right = new TreeNode(postorder[index-1]);
        //         frontNode->right = right;
        //         visited.insert(postorder[index-1]);
        //         q.push(right);
        //     }
        // }
        // return root;
    }
};