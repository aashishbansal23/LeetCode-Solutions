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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL){
            return head;
        }else if(head->next == NULL){
            delete head;
            return NULL;
        }else if(head->next->next == NULL){
            delete head->next;
            head->next = NULL;
            return head;
        }
        ListNode* pre = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next == NULL){
            pre->next = slow->next;
            slow->next = NULL;
            delete slow;
            return head;
        }else{
            pre = slow->next;
            slow->next = pre->next;
            pre->next = NULL;
            delete pre;
            return head;
        }
    }
};