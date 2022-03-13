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
        // Without Using Extra Space
        
        if(head == NULL){
            return NULL;
        }
        
        Node* temp = head;
        while(temp != NULL){
            Node* t = new Node(temp->val);
            t->next = temp->next;
            temp->next = t;
            temp = t->next;
        }
        
        temp = head;
        Node* new_head = NULL;
        Node* new_tail = NULL;
        Node* tail = NULL;
        while(temp!=NULL && temp->next!=NULL){
            if(temp->random == NULL){
                temp->next->random = NULL;
            }else{
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        
        temp = head;
        while(temp!=NULL && temp->next!=NULL){
            tail = temp;
            if(new_head == NULL){
                new_head = temp->next;
                new_tail = temp->next;
            }else{
                new_tail->next = temp->next;
                new_tail = new_tail->next;
            }
            temp->next = temp->next->next;
            temp = temp->next;
        }
        tail->next = NULL;
        return new_head;
        
         
        /*
        
        // Using Extra Space
        
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
        */
    }
};