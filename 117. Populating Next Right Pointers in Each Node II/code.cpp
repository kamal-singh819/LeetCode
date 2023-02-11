/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return NULL;
        
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int siz = q.size();

            Node* front = q.front();
            q.pop();
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
            siz--;
            if(q.empty()){
                front->next = NULL;
            }
            
            while(siz > 0){
                Node* temp = q.front();
                q.pop();
                front->next = temp;
                front = temp;

                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);

                siz--;
            }
        }
        return root;
        
    }
};
