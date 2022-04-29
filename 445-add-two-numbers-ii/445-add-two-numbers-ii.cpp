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
        stack<ListNode*> s1, s2;
        ListNode* temp = l1;
        while(temp != NULL){
            s1.push(temp);
            temp = temp->next;
        }
        temp = l2;
        while(temp != NULL){
            s2.push(temp);
            temp = temp->next;
        }
        int carry = 0;
        bool flag = s1.size() > s2.size();
        temp = NULL;
        while(!s1.empty() && !s2.empty()){
            if(flag){
                s1.top()->val += s2.top()->val+carry;
                s2.pop();
                if(s1.top()->val > 9){
                    carry = 1;
                    s1.top()->val = s1.top()->val%10;
                }else{
                    carry = 0;
                }
                temp = s1.top();
                s1.pop();
            }else{
                s2.top()->val += s1.top()->val+carry;
                s1.pop();
                if(s2.top()->val > 9){
                    carry = 1;
                    s2.top()->val = s2.top()->val%10;
                }else{
                    carry = 0;
                }
                temp = s2.top();
                s2.pop();
            }
        }
        if(flag){
            while(!s1.empty()){
                s1.top()->val += carry;
                if(s1.top()->val > 9){
                    carry = 1;
                    s1.top()->val = s1.top()->val%10;
                }else{
                    carry = 0;
                }
                temp = s1.top();
                s1.pop();
            }
            if(carry == 1){
                ListNode* new_node = new ListNode(1, temp);
                return new_node;
            }else{
                return temp;
            }
        }else{
            while(!s2.empty()){
                s2.top()->val += carry;
                if(s2.top()->val > 9){
                    carry = 1;
                    s2.top()->val = s2.top()->val%10;
                }else{
                    carry = 0;
                }
                temp = s2.top();
                s2.pop();
            }
            if(carry == 1){
                ListNode* new_node = new ListNode(1, temp);
                return new_node;
            }else{
                return temp;
            }
        }
    }
};