/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return root;
        }
        int count = 1;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int curr_count = 0;
            Node* curr = q.front();
            q.pop();
            curr_count++;
            int temp = 0;
            if(curr->left != NULL){
                q.push(curr->left);
                temp++;
            }
            if(curr->right != NULL){
                q.push(curr->right);
                temp++;
            }
            while(curr_count < count){
                curr->next = q.front();
                curr = q.front();
                q.pop();
                curr_count++;
                if(curr->left != NULL){
                    q.push(curr->left);
                    temp++;
                }
                if(curr->right != NULL){
                    q.push(curr->right);
                    temp++;
                }
            }
            count = temp;
        }
        return root;
    }
};