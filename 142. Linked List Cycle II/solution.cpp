/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//METHOD - I  USING UNORDERED_SET
class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        unordered_set<ListNode*> st;
        while(head != NULL){
            if(st.count(head) < 1)
                st.insert(head);
            else if(st.count(head) == 1){
                return head;
            } 
            
            else if(head == NULL)
                return NULL;
            
            head = head->next;        
        }
        return NULL;
        
    }
};
