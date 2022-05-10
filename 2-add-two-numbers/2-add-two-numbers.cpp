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
        ListNode* l = new ListNode();
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* cur = l;
        int sum = 0;
        int carry = 0;
        
        while (true) {
            if (cur1) {
                sum += cur1->val;
                cur1 = cur1->next;
            }
            if (cur2) {
                sum += cur2->val;
                cur2 = cur2->next;
            }
            sum += carry;
            cur->val = sum % 10;
            carry = sum / 10;
            sum = 0;
            if (cur1 || cur2 || carry) {
                cur->next = new ListNode();
                cur = cur->next;
            } else {
                return l;
            }
            
        }
        return l;
        
        
        /*
        ListNode* l3 = new ListNode();

            l3->val = l1->val;
            l3->next = l1->next;
        
        ListNode* curl3 = l3;
           ListNode* curl1 = l1;

        
        ListNode* curl2 = l2;
        int carry = 0;
        while (curl2 != NULL){
            curl3->val += (curl2->val + carry);
            if (curl3->val > 9){
                curl3->val  -= 10;
                carry = 1;
                
            }else carry = 0;
            curl2 = curl2->next;
            curl3 ->next = new ListNode(curl3->val);
        }
        if (carry = 1) curl3->next = new ListNode(1);

        return l3;
        */
    }
};