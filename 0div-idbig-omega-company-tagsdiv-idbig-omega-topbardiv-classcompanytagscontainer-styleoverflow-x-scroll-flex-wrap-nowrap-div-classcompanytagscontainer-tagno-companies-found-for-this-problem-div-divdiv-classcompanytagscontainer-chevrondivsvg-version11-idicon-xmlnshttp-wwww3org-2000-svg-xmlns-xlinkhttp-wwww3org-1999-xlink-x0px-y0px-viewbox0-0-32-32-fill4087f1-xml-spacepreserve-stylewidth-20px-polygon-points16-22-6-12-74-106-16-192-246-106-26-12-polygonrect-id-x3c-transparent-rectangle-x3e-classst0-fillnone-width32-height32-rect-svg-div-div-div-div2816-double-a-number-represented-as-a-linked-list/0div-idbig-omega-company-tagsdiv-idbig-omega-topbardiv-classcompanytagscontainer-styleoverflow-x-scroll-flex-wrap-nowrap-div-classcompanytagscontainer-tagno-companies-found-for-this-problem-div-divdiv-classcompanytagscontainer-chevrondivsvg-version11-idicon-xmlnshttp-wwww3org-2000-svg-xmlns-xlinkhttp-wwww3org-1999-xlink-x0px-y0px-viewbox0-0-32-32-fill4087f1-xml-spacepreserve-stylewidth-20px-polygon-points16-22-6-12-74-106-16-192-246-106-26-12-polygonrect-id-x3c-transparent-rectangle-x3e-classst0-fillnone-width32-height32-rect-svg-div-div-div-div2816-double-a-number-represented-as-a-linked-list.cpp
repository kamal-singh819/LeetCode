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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = head;
        
        while(curr != NULL){
            forward = forward ->next;
            curr ->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        ListNode* temp = head;
        int carry = 0;
        ListNode* last = NULL;
        
        while(temp != NULL){
            if(temp ->next == NULL) last = temp;
            int num = temp->val * 2 + carry;
            carry = num/10;
            num = num%10;
            temp->val = num;
            temp = temp->next;
        }
        if(carry != 0){
            ListNode* newNode = new ListNode(carry);
            last->next = newNode;
        }
        return reverse(head);
    }
};