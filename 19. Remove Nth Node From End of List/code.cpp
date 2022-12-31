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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int siz = 0; //length of the linked list
        while(temp != NULL){
            siz++;
            temp = temp->next;
        }
        int start = siz-n+1;
        temp = head;
        if(start == 1){
            head = head->next;
            temp->next = NULL;
            delete temp;
            return head;
        }
        for(int i=1; i<start-1; i++){
            temp = temp->next;
        }
        ListNode* del = NULL;
        del = temp->next;
        temp->next = del->next;
        del->next = NULL;
        delete del;

        return head;  
    }
};
