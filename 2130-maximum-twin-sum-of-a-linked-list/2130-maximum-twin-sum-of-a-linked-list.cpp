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
    int pairSum(ListNode* head) {
        //two pointers to get to the half
        ListNode* slowpointer = head;
        ListNode* fastpointer = head;
        while (fastpointer) {
            slowpointer = slowpointer->next;
            fastpointer = fastpointer->next->next;
        }
        //slow pointer points to the start of the second half of the linked list
        slowpointer = reverse(slowpointer); //now slowpointer points to the new start (n - 1) of the second half
        fastpointer = head;
        int maxSum = INT_MIN;
        while (slowpointer) {
            maxSum = max(maxSum, slowpointer->val + fastpointer->val);
            slowpointer = slowpointer->next;
            fastpointer = fastpointer->next;
        }
        return maxSum;
    }
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* nextnode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextnode;
        }
        return prev;
    }
    
    
};