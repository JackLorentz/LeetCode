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
        int carry = 0;
        ListNode* tail = nullptr;
        ListNode* head = nullptr;
        while(l1 && l2){
            ListNode* tmp = new ListNode(0);
            tmp->val = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            tmp->next = nullptr;
            if(tail){
                tail->next = tmp;
            }
            tail = tmp;
            if(!head){
                head = tail;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 && !l2){
            ListNode* tmp = new ListNode(0);
            tmp->val = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            tmp->next = nullptr;
            if(tail){
                tail->next = tmp;
            }
            tail = tmp;
            if(!head){
                head = tail;
            }
            l1 = l1->next;
        }
        while(!l1 && l2){
            ListNode* tmp = new ListNode(0);
            tmp->val = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            tmp->next = nullptr;
            if(tail){
                tail->next = tmp;
            }
            tail = tmp;
            if(!head){
                head = tail;
            }
            l2 = l2->next;
        }
        if(carry > 0){
            ListNode* tmp = new ListNode(0);
            tmp->val = carry;
            tmp->next = nullptr;
            if(tail){
                tail->next = tmp;
            }
            tail = tmp;
            if(!head){
                head = tail;
            }
        }
        return head;
    }
};