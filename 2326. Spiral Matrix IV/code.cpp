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
    vector<vector<int> > spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int> > v(m, vector<int> (n, -1));
        int startRow = 0, startCol = 0;
        int endRow = m-1, endCol = n-1;
        int i, j;
        while(head != NULL){
            j = startCol;
            while(j <= endCol && head != NULL){
                v[startRow][j] = head->val;
                j++;
                head = head->next;
            }
            startRow++;

            i = startRow;
            while(i <= endRow && head != NULL){
                v[i][endCol] = head->val;
                i++;
                head = head->next;
            }
            endCol--;

            j = endCol;
            while(j >= startCol && head != NULL){
                v[endRow][j] = head->val;
                j--;
                head = head->next;
            }
            endRow--;

            i = endRow;
            while(i >= startRow && head != NULL){
                v[i][startCol] = head->val;
                i--;
                head = head->next;
            }
            startCol++;
        }
        return v;
        
    }
};
