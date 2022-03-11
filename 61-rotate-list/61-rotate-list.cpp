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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        int size = 0;
        ListNode* temp = head;
        ListNode* tail = head;
        while(temp != NULL){
            tail = temp;
            size++;
            temp = temp->next;
        }
        int num = size-k-1;
        while(num < 0){
            num += size;
        }
        temp = head;
        while(num > 0){
            temp = temp->next;
            num--;
        }
        if(temp != tail){
            tail->next = head;
            head = temp->next;
            temp->next = NULL;
            
        }
        return head;
    }
};