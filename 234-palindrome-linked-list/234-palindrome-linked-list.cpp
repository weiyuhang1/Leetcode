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
    bool isPalindrome(ListNode* head) {
         if (!head) return true;
    
        //head would not be a nullptr, at least one node
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {//mid left
            fast = fast->next->next;
            slow = slow->next;
        }
        

        ListNode* start_right_half = reverseList(slow->next);
        //compare
        ListNode* cur = head;
        ListNode* r = start_right_half;
        while (r) {
            if (cur->val != r-> val) 
                return false;
            cur = cur->next;
            r = r->next;
            }
        
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = NULL;
        while (cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
/*        
        
    }
    
    
public:
    
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
    
        //head would not be a nullptr, at least one node
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {//mid left
            fast = fast->next->next;
            slow = slow->next;
        }
        

        ListNode* start_right_half = reverseList(slow->next);
        //compare
        ListNode* cur = head;
        ListNode* r = start_right_half;
        while (r) {
            if (cur->val != r-> val) 
                return false;
            cur = cur->next;
            r = r->next;
            }
        }
        return true;*/
        
    }
};