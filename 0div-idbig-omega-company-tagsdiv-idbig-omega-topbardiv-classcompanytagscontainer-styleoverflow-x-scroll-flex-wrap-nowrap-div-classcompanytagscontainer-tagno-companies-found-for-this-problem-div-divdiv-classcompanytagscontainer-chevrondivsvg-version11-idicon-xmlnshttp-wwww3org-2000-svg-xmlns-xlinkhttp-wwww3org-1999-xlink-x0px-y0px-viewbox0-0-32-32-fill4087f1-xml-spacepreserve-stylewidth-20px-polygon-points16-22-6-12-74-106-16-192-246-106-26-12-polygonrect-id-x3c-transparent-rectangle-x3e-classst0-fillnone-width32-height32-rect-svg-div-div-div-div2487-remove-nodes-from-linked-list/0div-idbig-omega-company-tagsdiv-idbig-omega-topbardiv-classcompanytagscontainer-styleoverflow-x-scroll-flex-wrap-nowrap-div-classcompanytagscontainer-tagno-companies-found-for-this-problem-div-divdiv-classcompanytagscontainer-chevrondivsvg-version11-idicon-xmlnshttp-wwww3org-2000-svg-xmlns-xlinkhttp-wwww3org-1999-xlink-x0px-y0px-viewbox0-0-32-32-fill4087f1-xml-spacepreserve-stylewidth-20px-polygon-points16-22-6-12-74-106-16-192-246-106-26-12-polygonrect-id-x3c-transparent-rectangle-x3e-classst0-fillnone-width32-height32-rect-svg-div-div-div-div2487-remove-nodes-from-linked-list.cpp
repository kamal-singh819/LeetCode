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
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = head->next;
        while(curr != NULL) {
            curr ->next = prev;
            prev = curr;
            curr = forward;
            if(forward != NULL) forward = forward ->next;
        }
        return prev;  
    }
public:
    ListNode* removeNodes(ListNode* head) {
        if(head->next == NULL) return head;
        head = reverse(head);
        int mx = head->val;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr != NULL){
            if(curr->val < mx){
                ListNode* p = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete p;
            }
            else {
                mx = curr -> val;
                curr = curr->next;
                prev = prev->next;
            }
        }
        head = reverse(head);
        return head;
    }
};