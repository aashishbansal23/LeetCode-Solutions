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
class Solution {
    ListNode* merge(ListNode* head1, ListNode* head2){
        if(head1 == NULL){
            return head2;
        }
        if(head2 == NULL){
            return head1;
        }
        
        ListNode* ans = NULL;
        ListNode* temp = NULL;
        while(head1!=NULL && head2!=NULL){
            if(head1->val < head2->val){
                if(ans == NULL){
                    ans = head1;
                    temp = head1;
                }else{
                    temp->next = head1;
                    temp = temp->next;
                }
                head1 = head1->next;
            }else{
                if(ans == NULL){
                    ans = head2;
                    temp = head2;
                }else{
                    temp->next = head2;
                    temp = temp->next;
                }
                head2 = head2->next;
            }
        }
        
        while(head1 != NULL){
            if(ans == NULL){
                ans = head1;
                temp = head1;
            }else{
                temp->next = head1;
                temp = temp->next;
            }
            head1 = head1->next;
        }
        
        while(head2 != NULL){
            if(ans == NULL){
                ans = head2;
                temp = head2;
            }else{
                temp->next = head2;
                temp = temp->next;
            }
            head2 = head2->next;
        }
        return ans;
    }
    
    class Node{
        public:
        ListNode* currNode;
        int data;
        Node(){
            currNode = NULL;
            data = 0;
        }
        Node(ListNode* currNode, int data){
            this->currNode = currNode;
            this->data = data;
        }
    };
    
    class compator{
        public:
        bool operator ()(Node a, Node b){
            return a.data>b.data;
        }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        ListNode* ans = NULL;
        ListNode* tail = NULL;
        priority_queue<Node, vector<Node>, compator> pq;
        for(int i=0; i<size; i++){
            if(lists[i] == NULL){
                continue;
            }
            Node temp(lists[i], lists[i]->val);
            pq.push(temp);
        }
        while(!pq.empty()){
            Node front = pq.top();
            pq.pop();
            if(front.currNode->next != NULL){
                Node temp(front.currNode->next, front.currNode->next->val);
                pq.push(temp);
            }
            if(ans == NULL){
                ans = front.currNode;
                tail = front.currNode;
            }else{
                tail->next = front.currNode;
                tail = tail->next;
            }
            tail->next = NULL;
        }
        return ans;
        
        
        
        
        // First Try
//         int k = lists.size();
//         if(k == 0){
//             return NULL;
//         }else if(k == 1){
//             return lists[0];
//         }
        
//         ListNode* ans = lists[0];
//         for(int i=1; i<k; i++){
//             ans = merge(ans, lists[i]);
//         }
//         return ans;
    }
};