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
    ListNode* removeNodes(ListNode* head) {
        deque<ListNode*> dq;
        ListNode* temp = head;
        while(temp != NULL){
            if(dq.empty()){
                dq.push_back(temp);
                temp = temp->next;
            }
            else{
                if(temp->val <= dq.back()->val){
                    dq.push_back(temp);
                    temp = temp->next;
                }
                else{
                    while(!dq.empty() && temp->val > dq.back()->val)
                        dq.pop_back();
                }
            }
        }
        head = NULL;
        temp = NULL;
        while(!dq.empty()){
            if(head == NULL){
                head = dq.front();
                temp = head;
                dq.pop_front();
            }else{
                temp->next = dq.front();
                dq.pop_front();
                temp = temp->next;
            }
        }
        return head;
        
    }
};
