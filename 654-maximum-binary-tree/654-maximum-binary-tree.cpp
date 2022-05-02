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
    TreeNode* constructMaximumBinaryTree_help(vector<int>& nums, int i, int j){
        if(i > j){
            return NULL;
        }
        int index = i;
        for(int k=i; k<=j; k++){
            if(nums[k] > nums[index]){
                index = k;
            }
        }
        TreeNode* newNode = new TreeNode(nums[index], constructMaximumBinaryTree_help(nums, i, index-1), constructMaximumBinaryTree_help(nums, index+1, j));
        return newNode;
    }
    
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree_help(nums, 0, nums.size()-1);
    }
};