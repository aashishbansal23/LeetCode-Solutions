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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }else if(l2==NULL){
            return l1;
        }
        ListNode* ans = NULL;
        ListNode* iter = NULL;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        while(temp1!=NULL && temp2!=NULL){
            int sum = temp1->val+temp2->val+carry;
            if(sum>9){
                carry = 1;
                sum = sum%10;
            }else{
                carry = 0;
            }
            if(ans==NULL){
                ans = new ListNode(sum);
                iter = ans;
            }else{
                iter->next = new ListNode(sum);
                iter = iter->next;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1 != NULL){
            int sum = temp1->val+carry;
            if(sum>9){
                carry = 1;
                sum = sum%10;
            }else{
                carry = 0;
            }
            iter->next = new ListNode(sum);
            temp1 = temp1->next;
            iter = iter->next;
        }
        while(temp2 != NULL){
            int sum = temp2->val+carry;
            if(sum>9){
                carry = 1;
                sum = sum%10;
            }else{
                carry = 0;
            }
            iter->next = new ListNode(sum);
            temp2 = temp2->next;
            iter = iter->next;
        }
        if(carry == 1){
            iter->next = new ListNode(carry);
        }
        return ans;
    }
};