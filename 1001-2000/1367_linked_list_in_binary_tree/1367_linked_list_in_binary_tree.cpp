/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath_true(ListNode* head, TreeNode* root){
        if(head == NULL){
            return true;
        }
        if(root==NULL || head->val!=root->val){
            return false;
        }
        return (isSubPath_true(head->next, root->left) || isSubPath_true(head->next, root->right));
    }
    
    bool isSubPath_help(ListNode* head, TreeNode* root){
        if(head == NULL){
            return true;
        }
        if(root == NULL){
            return false;
        }
        if(isSubPath_true(head, root)){
            return true;
        }
        return (isSubPath_help(head, root->left) || isSubPath_help(head, root->right));
    }
    
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return isSubPath_help(head, root);
    }
};