//Node class
class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        next = nullptr;
    }
};
class MyLinkedList {
public:
    Node* head;
    int size;
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size) return -1;
        Node* temp = head;
        for(int i=0; i<index; i++){
            temp = temp->next;
        }
        return temp->val;   
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;  
        size++;  
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);   
    }
    
    void addAtIndex(int index, int val) {
        if(index > size || index < 0) return;
        Node* newNode = new Node(val);
        if(index == 0){
            addAtHead(val);
        }
        else{
            Node* prev = head;
            Node* forward = NULL;
            for(int i=1; i<index; ++i){
                prev = prev->next;
            }
            forward = prev->next; //now insert the node between prev and forward
            newNode->next = forward; 
            prev->next = newNode;
            size++;
        } 
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;
        if(index == 0){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else{
            Node* temp = head;
            for(int i=1; i<index; i++){
                temp = temp->next;
            }
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
        }
        size--; 
    }
    //dectructor to free up the space
    ~MyLinkedList(){
        Node* p = head;
        while(head){
            head = head->next;
            delete p;
            p = head;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
