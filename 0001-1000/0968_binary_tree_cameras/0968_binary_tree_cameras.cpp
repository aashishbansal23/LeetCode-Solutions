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
    void dfs(TreeNode* root, TreeNode* parent, set<TreeNode*>& visited, int& ans){
        if(root == NULL){
            return ;
        }
        dfs(root->left, root, visited, ans);
        dfs(root->right, root, visited, ans);
        if(parent==NULL && visited.count(root)==0 || visited.count(root->left)==0 || visited.count(root->right)==0){
            ans++;
            visited.insert(parent);
            visited.insert(root);
            visited.insert(root->left);
            visited.insert(root->right);
        }
    }
    
    int dfsUsingDP(TreeNode* root, int& ans){
        if(root == NULL){
            return 1;
        }
        int leftAns = dfsUsingDP(root->left, ans);
        int rightAns = dfsUsingDP(root->right, ans);
        if(leftAns==0 || rightAns==0){
            ans++;
            return 2;
        }else if(leftAns==2 || rightAns==2){
            return 1;
        }else{
            return 0;
        }
    }
    
public:
    int minCameraCover(TreeNode* root) {
        int ans = 0;
        // 0 -> No Camera is covering this node
        // 1 -> Covered with the camera
        // 2 -> node has camera
        int rootAns = dfsUsingDP(root, ans);
        if(rootAns == 0){
            ans++;
        }
        return ans;
        
        
        
        
        
        
        // First Try
        // int ans = 0;
        // set<TreeNode*> visited;
        // visited.insert(NULL);
        // dfs(root, NULL, visited, ans);
        // return ans;
    }
};