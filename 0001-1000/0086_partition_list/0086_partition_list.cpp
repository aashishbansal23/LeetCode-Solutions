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
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* new_head = NULL;
        ListNode* temp1 = NULL;
        ListNode* temp_head = NULL;
        ListNode* temp2 = NULL;
        while(head != NULL){
            if(head->val < x){
                if(new_head == NULL){
                    new_head = head;
                    temp1 = head;
                }else{
                    temp1->next = head;
                    temp1 = head;
                }
            }else{
                if(temp_head == NULL){
                    temp_head = head;
                    temp2 = head;
                }else{
                    temp2->next = head;
                    temp2 = head;
                }
            }
            head = head->next;
        }
        if(new_head == NULL){
            if(temp2 != NULL){
                temp2->next = NULL;
            }
            return temp_head;
        }else{
            temp1->next = temp_head;
            if(temp2 != NULL){
                temp2->next = NULL;
            }
            return new_head;
        }
    }
};