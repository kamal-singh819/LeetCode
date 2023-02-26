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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(head != NULL){
            head = head->next;
            curr->next = prev;
            prev = curr;
            curr = head;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;
        ListNode* newhead = new ListNode(0);
        ListNode* temp = newhead;

        while(head != NULL){
            int i=1;
            ListNode* front = head;
            ListNode* last = head;
            while(last->next != NULL && i < k){
                last = last->next;
                i++;
            }
            if(i == k){
                head = last->next;
                last->next = NULL;
            
                ListNode* reversed =  reverseList(front);
                temp->next = reversed;
                temp = reversed;
                for(int i=1; i<k; i++){
                    temp = temp->next;
                }
            }
            else{
                temp->next = front;
                break;
            }
        }

        return newhead->next;
        
    }
};
