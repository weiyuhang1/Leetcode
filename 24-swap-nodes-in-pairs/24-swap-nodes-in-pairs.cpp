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
    ListNode* swapPairs(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* tmp;
        while (cur != NULL  && cur->next != NULL) {
            if (pre == NULL) {
                tmp = cur->next->next;
                head = cur->next;
                head->next = cur;
                cur->next = tmp;
                pre = cur;
                cur = tmp;
        
                
            }else{
                tmp = cur->next->next;
                pre->next = cur->next;
                pre->next->next = cur;
                cur->next = tmp;
                pre = cur;
                cur = tmp;
               
            }
        }
        return head;
    }
};