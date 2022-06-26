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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return head;
        }
        ListNode* temp = head;
        ListNode* pre = NULL;
        while(temp != NULL){
            if(temp->val == val){
                if(pre == NULL){
                    head = temp->next;
                    temp->next = NULL;
                    delete temp;
                    temp = head;
                }else{
                    pre->next = temp->next;
                    temp->next = NULL;
                    delete temp;
                    temp = pre->next;
                }
            }else{
                pre = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};