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
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* pre = NULL;
        ListNode* temp = head;
        ListNode* next = NULL;
        while(temp != NULL){
            next = temp->next;
            temp->next = pre;
            pre = temp;
            temp = next;
        }
        return pre;
    }
    
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL || left >= right){
            return head;
        }
        
        ListNode* temp = head;
        int i=1;
        ListNode* pre = NULL;
        ListNode* temp_head = NULL;
        
        while(temp!=NULL && i<left){
            pre = temp;
            temp = temp->next;
            i++;
        }
        if(i==left && temp!=NULL){
            temp_head = temp;
        }else{
            return head;
        }
        
        while(temp!=NULL && i<right){
            temp = temp->next;
            i++;
        }
        ListNode* last = temp->next;
        temp->next = NULL;
        if(pre!=NULL){
            pre->next = NULL;
        }
        temp_head = reverse(temp_head);
        temp = temp_head;
        while(temp!=NULL && temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = last;
        if(pre == NULL){
            return temp_head;
        }
        pre->next = temp_head;
        return head;
    }
};