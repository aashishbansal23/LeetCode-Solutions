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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL){
            return l1;
        }else if(l1==NULL){
            return l2;
        }else if(l2==NULL){
            return l1;
        }
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* ans = NULL;
        ListNode* result;
        
        while(l1!=NULL && l2!=NULL){
            if(l1->val > l2->val){
                if(ans==NULL){
                    ans = l2;
                    result = ans;
                }else{
                    ans->next = l2;
                    ans = ans->next;
                }
                l2 = l2->next;
            }else{
                if(ans==NULL){
                    ans = l1;
                    result = ans;
                }else{
                    ans->next = l1;
                    ans = ans->next;
                }
                l1 = l1->next;
            }
        }
        while(l1!=NULL){
            ans->next = l1;
            ans = ans->next;
            l1 = l1->next;
        }
        while(l2!=NULL){
            ans->next = l2;
            ans = ans->next;
            l2 = l2->next;
        }
        ans->next = NULL;
        return result;
    }
};