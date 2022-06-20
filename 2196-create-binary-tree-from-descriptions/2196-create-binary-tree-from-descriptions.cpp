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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        set<TreeNode*> parents;
        unordered_map<int, TreeNode*> mp;
        for(auto node:descriptions){
            TreeNode* parent = NULL;
            TreeNode* child = NULL;
            if(mp.count(node[0]) > 0){
                parent = mp[node[0]];
            }else{
                parent = new TreeNode(node[0]);
                parents.insert(parent);
                mp[node[0]] = parent;
            }
            if(mp.count(node[1]) > 0){
                child = mp[node[1]];
                if(parents.count(child) > 0){
                    parents.erase(child);
                }
            }else{
                child = new TreeNode(node[1]);
                mp[node[1]] = child;
            }
            if(node[2] == 1){
                parent->left = child;
            }else{
                parent->right = child;
            }
        }
        return *parents.begin();
    }
};