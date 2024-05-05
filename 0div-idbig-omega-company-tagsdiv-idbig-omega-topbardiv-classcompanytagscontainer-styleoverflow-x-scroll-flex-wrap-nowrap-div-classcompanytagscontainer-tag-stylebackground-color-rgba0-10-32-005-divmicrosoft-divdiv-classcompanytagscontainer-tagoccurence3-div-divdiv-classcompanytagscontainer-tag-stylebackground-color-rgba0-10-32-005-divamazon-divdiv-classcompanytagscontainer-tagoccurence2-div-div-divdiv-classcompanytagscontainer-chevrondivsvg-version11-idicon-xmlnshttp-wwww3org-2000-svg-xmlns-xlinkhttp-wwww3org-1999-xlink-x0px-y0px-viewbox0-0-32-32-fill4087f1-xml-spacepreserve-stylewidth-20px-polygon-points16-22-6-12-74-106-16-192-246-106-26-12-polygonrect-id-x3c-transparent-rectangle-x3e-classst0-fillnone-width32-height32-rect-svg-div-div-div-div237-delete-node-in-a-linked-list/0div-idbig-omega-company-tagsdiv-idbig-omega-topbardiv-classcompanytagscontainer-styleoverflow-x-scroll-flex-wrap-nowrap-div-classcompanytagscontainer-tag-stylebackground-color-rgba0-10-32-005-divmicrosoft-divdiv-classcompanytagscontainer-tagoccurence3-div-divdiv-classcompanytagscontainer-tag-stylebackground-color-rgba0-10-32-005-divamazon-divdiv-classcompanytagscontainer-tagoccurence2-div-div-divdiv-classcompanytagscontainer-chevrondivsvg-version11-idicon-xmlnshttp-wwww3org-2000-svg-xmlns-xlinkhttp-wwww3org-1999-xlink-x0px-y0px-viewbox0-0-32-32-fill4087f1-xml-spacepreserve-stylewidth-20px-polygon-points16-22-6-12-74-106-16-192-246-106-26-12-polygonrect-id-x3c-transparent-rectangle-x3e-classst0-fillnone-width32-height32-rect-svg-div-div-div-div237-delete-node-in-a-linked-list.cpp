/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* p = NULL;
        ListNode* q = node;
        ListNode* r = node->next;
        
        while(r != NULL) {
            q->val = r->val;
            p = q;
            q = q->next;
            r = r->next;
        }
        p->next = NULL;
        delete q;
    }
};