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
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int total = size;
            double sum = 0;
            while(size-- > 0){
                TreeNode* currNode = q.front();
                q.pop();
                sum += currNode->val;
                if(currNode->left != NULL){
                    q.push(currNode->left);
                }
                if(currNode->right != NULL){
                    q.push(currNode->right);
                }
            }
            sum /= total;
            ans.push_back(sum);
        }
        return ans;
    }
};