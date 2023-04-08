/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    void dfs(Node* node, Node* copy, unordered_map<Node*, Node*> &visited){
        visited[node] = copy;
        for(auto neigh : node->neighbors){
            //if neigh ki copy nahi bani hai to bna denge
            if(!visited[neigh]){
                Node* newNode = new Node(neigh->val);
                (copy->neighbors).push_back(newNode);
                dfs(neigh, newNode, visited);
            }
            //else neigh ki copy ban chuki hai to 'copy' ki list me neigh ki copy push kar denge
            else (copy->neighbors).push_back(visited[neigh]);
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        unordered_map<Node*, Node*> visited; //stores original -> copy
        Node* copy = new Node(node->val);
        //now iterate for all neighbours of node
        dfs(node, copy, visited); //since graph is connected no need to take a for loop
        return copy;  
    }
};
