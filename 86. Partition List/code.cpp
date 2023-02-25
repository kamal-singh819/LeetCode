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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL)
            return head;
        queue<ListNode*> q; //will store greater than x wale nodes
        ListNode* newhead = NULL;
        ListNode* temp = NULL;
        while(head != NULL){
            if(head->val < x){
                if(newhead == NULL){
                    newhead = head;
                    temp = head;
                }
                else{
                    temp->next = head;
                    temp = head;
                }
            }
            else{
                q.push(head);
            }
            head = head->next;
        }
        if(q.empty()) return newhead;
        if(newhead == NULL){
            newhead = q.front();
            q.pop();
            temp = newhead;
        }
        while(!q.empty()){
            temp->next = q.front();
            q.pop();
            temp = temp->next;
        }
        temp->next = NULL;
        return newhead;
        
        
    }
};
