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
    ListNode* reversedList(ListNode* head){
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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = NULL;
        ListNode* first = head->next; //second node of the original list assign to first------

        //reverse the second list
        second = reversedList(second);

        ListNode* temp = head;
        while(second != NULL && first != NULL){
            temp->next = second;
            temp = temp->next;
            second = second->next;
            if(second == NULL){
                temp->next = first;
                return;
            }

            temp->next = first;
            temp = temp->next;
            first = first->next;
        }
    }
};
