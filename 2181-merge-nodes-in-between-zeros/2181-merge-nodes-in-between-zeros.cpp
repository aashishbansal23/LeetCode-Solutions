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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head;
        ListNode* pre = NULL;
        ListNode* temp = head;
        int sum = 0;
        while(temp != NULL){
            if(temp->val==0 && sum!=0){
                curr->val = sum;
                pre = curr;
                curr = curr->next;
                sum = 0;
            }else{
                sum += temp->val;
            }
            temp = temp->next;
        }
        if(pre != NULL){
            pre->next = NULL;
        }
        return head;
    }
};