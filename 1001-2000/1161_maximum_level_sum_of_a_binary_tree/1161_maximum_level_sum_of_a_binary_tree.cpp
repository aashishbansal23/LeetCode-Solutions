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
    int maxLevelSum(TreeNode* root) {
        if(!root){
            return 0;
        }
        int ansSum = INT_MIN;
        int ansLevel = 1;
        int currSum = 0;
        int currLevel = 1;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){\
            TreeNode* frontNode = q.front();
            q.pop();
            if(!frontNode){
                if(ansSum < currSum){
                    ansSum = currSum;
                    ansLevel = currLevel;
                }
                if(q.empty()){
                    break;
                }
                currSum = 0;
                q.push(NULL);
                currLevel++;
            }else{
                currSum += frontNode->val;
                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }
        }
        return ansLevel;
    }
};