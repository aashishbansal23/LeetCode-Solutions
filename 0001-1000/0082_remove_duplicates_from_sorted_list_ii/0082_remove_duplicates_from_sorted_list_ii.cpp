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
        unordered_map<int, int> ourmap;
        ListNode* temp = head;
        while(temp != NULL){
            if(ourmap.count(temp->val) > 0){
                ourmap[temp->val]++;
            }else{
                ourmap[temp->val] = 1;
            }
            temp = temp->next;
        }
        temp = head;
        ListNode* pre = NULL;
        while(temp != NULL){
            if(ourmap[temp->val] > 1){
                if(pre == NULL){
                    head = head->next;
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