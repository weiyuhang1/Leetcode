/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        Node* leftmost = root;
        Node* cur;
        Node* pre = nullptr;
        while (leftmost) {
            cur = leftmost;
            leftmost = nullptr;
            
            while (cur) {
                processChild(cur->left, pre, leftmost);
                processChild(cur->right, pre, leftmost);
                cur = cur->next;
            }
        }
        return root;
    }
private:
    void processChild(Node* child, Node*& pre, Node*& leftmost) {
        if (child == nullptr) return;
        if (leftmost == nullptr) {
            pre = child;
            leftmost = child;
        } else {
            pre->next = child;
            pre = child;
        }
    }
    
};