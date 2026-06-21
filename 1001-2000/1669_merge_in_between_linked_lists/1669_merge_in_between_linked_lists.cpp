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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* first = NULL;
        ListNode* second = NULL;
        ListNode* temp = list1;
        int i = 0;
        while(i <= b){
            if(i < a){
                first = temp;
            }
            second = temp;
            temp = temp->next;
            i++;
        }
        first->next = list2;
        first = list2;
        while(first->next != NULL){
            first = first->next;
        }
        first->next = second->next;
        second->next = NULL;
        return list1;
    }
};