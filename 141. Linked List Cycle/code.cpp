/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//METHOD - I    USING SLOW-FAST POINTER APPROACH...
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        if(head->next == NULL)
            return false;
        if(head->next == head)
            return true;    
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;
            }
            if(slow == NULL || fast == NULL || fast->next == NULL)
                return false;
        }
        return true;
        
    }
};


//METHOD - II    USING UNORDERED_SET

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> st;
        while(head != NULL){
            if(st.count(head) < 1)
                st.insert(head);
            else if(st.count(head) == 1){
                return true;
            }      
            else if(head == NULL)
                return false;      
            head = head->next;        
        }
        return false;      
    }
};
