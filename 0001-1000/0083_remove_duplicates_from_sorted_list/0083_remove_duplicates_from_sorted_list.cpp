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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp = head;
        int value = temp->val;
        while(temp->next != NULL){
            if(temp->next->val == value){
                ListNode* t1 = temp->next;
                temp->next = t1->next;
                t1->next = NULL;
                delete t1;
            }else{
                temp = temp->next;
                value = temp->val;
            }
        }
        return head;
    }
};