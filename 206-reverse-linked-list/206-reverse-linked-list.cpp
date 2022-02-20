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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* current = head;
        ListNode* tmp;
        while (current != NULL) {
            tmp = current->next;
            current->next = pre;
            pre = current;
            current = tmp;
            
        }
        return pre;
        
    }
};