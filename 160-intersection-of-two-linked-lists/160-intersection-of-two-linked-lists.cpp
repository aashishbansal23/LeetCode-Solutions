/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL){
            return NULL;
        }
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while(temp1!=NULL){
            temp2 = headB;
            while(temp2!=NULL){
                if(temp1 == temp2){
                    break;
                }
                temp2 = temp2->next;
            }
            if(temp1 == temp2){
                break;
            }
            temp1 = temp1->next;
        }
        if(temp1 == temp2){
            return temp1;
        }
        return NULL;
    }
};