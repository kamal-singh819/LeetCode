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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        while(head != NULL && head->val == val)
            head = head->next;
        
        ListNode* prev = NULL;
        while(temp != NULL){
            if(temp->val == val){
                ListNode* del = temp;
                temp = temp->next;
                if(prev != NULL)
                    prev->next = temp;
                delete del;
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
        
    }
};
