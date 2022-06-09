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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            int start = q.front().second;
            int end = 0;
            for(int i=0; i<size; i++){
                pair<TreeNode*, long long> front = q.front();
                q.pop();
                TreeNode* frontNode = front.first;
                long long nodeNumber = front.second-start;
                if(i == size-1){
                    end = nodeNumber;
                }
                if(frontNode->left != NULL){
                    q.push({frontNode->left, 2*nodeNumber+1});
                }
                if(frontNode->right != NULL){
                    q.push({frontNode->right, 2*nodeNumber+2});
                }
            }
            ans = max(ans, end+1);
        }
        return ans;
    }
};