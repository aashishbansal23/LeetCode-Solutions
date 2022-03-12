/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        
        Node* temp = head;
        Node* tail = NULL;
        Node* new_head = NULL;
        unordered_map<Node*, Node*> mp;
        while(temp != NULL){
            Node* t = new Node(temp->val);
            mp[temp] = t;
            if(new_head == NULL){
                new_head = t;
            }
            if(tail != NULL){
                tail->next = t;
            }
            tail = t;
            temp = temp->next;
        }
        
        temp = head;
        tail = new_head;
        while(temp!=NULL && tail!=NULL){
            if(temp->random == NULL){
                tail->random = NULL;
            }else{
                tail->random = mp[temp->random];
            }
            temp = temp->next;
            tail = tail->next;
        }
        return new_head;
    }
};