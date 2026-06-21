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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* temp = head;
        while(temp != NULL){
            ListNode* pre = NULL;
            ListNode* pre2 = head;
            ListNode* temp2 = head->next;
            while(temp2 != NULL){
                if(temp2->val < pre2->val){
                    if(pre == NULL){
                        pre2->next = temp2->next;
                        temp2->next = pre2;
                        pre = temp2;
                        pre2 = temp2;
                        temp2 = temp2->next;
                        temp = pre;
                        head = pre;
                    }else{
                        pre2->next = temp2->next;
                        temp2->next = pre2;
                        pre->next = temp2;
                        pre = temp2;
                        // pre2 = temp2;
                        temp2 = pre2->next;
                    }
                }else{
                    pre = pre2;
                    pre2 = temp2;
                    temp2 = temp2->next;
                }
            }
            temp = temp->next;
        }
        return head;
    }
};