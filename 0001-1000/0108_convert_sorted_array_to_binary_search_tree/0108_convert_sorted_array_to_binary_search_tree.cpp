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
    
    TreeNode* helper(vector<int>& nums, int st, int ed){
        if(st>ed){
            return NULL;
        }
        // cout << "hii" << endl;
        int mid = st+(ed-st)/2;
        struct TreeNode* root = new TreeNode;
        root->val = nums[mid];
        root->left = helper(nums, st, mid-1);
        root->right = helper(nums, mid+1, ed);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // cout << "hii" << endl;
        return helper(nums, 0, nums.size()-1);
    }
};