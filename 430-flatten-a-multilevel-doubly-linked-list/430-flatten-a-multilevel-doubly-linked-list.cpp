/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    Node* getFlatten(Node* head){
        if(head==NULL){
            return head;
        }
        Node* temp = head;
        Node* ans = NULL;
        while(temp != NULL){
            if(temp->child != NULL){
                Node* tail = getFlatten(temp->child);
                tail->next = temp->next;
                if(temp->next != NULL){
                    temp->next->prev = tail;
                }
                temp->next = temp->child;
                temp->child->prev = temp;
                temp->child = NULL;
                ans = tail;
                temp = tail->next;
            }else{
                ans = temp;
                temp = temp->next;
            }
        }
        return ans;
    }
    
public:
    Node* flatten(Node* head) {
        getFlatten(head);
        return head;
    }
};