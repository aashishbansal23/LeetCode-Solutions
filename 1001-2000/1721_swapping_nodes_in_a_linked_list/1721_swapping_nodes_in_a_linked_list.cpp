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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        
        if(k<0 || k>len){
            return head;
        }
        
        ListNode* pre = NULL;
        int i = 1;
        temp = head;
        while(i < k){
            temp = temp->next;
            i++;
        }
        pre = temp;
        i = 0;
        temp = head;
        while(i < len-k){
            temp = temp->next;
            i++;
        }
        swap(temp->val, pre->val);
        return head;
        
        
        // vector<int> temp_arr;
        // ListNode* temp = head;
        // while(temp != NULL){
        //     temp_arr.push_back(temp->val);
        //     temp = temp->next;
        // }
        // if(k>temp_arr.size() || k<=0){
        //     return head;
        // }
        // int t = temp_arr[k-1];
        // temp_arr[k-1] = temp_arr[temp_arr.size()-k];
        // temp_arr[temp_arr.size()-k] = t;
        // temp = head;
        // int i = 0;
        // while(temp != NULL){
        //     temp->val = temp_arr[i++];
        //     temp = temp->next;
        // }
        // return head;
    }
};