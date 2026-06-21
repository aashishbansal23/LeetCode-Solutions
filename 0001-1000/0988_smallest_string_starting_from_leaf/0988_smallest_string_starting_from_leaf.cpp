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
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        queue<pair<TreeNode*, string>> q;
        q.push({root, ""});
        while(!q.empty()){
            auto [node, s] = q.front();
            q.pop();
            s.push_back('a'+node->val);
            if(!node->left && !node->right){
                reverse(s.begin(), s.end());
                if(ans == ""){
                    ans = s;
                }else{
                    ans = min(ans, s);
                }
                continue;
            }
            if(node->left){
                q.push({node->left, s});
            }
            if(node->right){
                q.push({node->right, s});
            }
        }
        return ans;
    }
};