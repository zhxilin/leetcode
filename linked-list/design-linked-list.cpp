//707. Design Linked List
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        size = 0;
        head = tail = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {        
        if (!head || index >= size) return -1;
        
        Node* cur = getNode(index);
        
        return cur ? cur->val : -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* cur = new Node(val);
        
        if (0 == size)
            head = tail = cur;
        else {
            cur->next = head;
            head->prev = cur;
            head = cur;
        }
        
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* cur = new Node(val);
        
        if (0 == size)
            head = tail = cur;
        else {
            tail->next = cur;
            cur->prev = tail;
            tail = cur;
        }
        
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index >= size)
            addAtTail(val);
        else if (0 == index)
            addAtHead(val);
        else {
            Node* cur = getNode(index);
            Node* node = new Node(val);
          
            node->prev = cur->prev;
            node->next = cur;
            node->prev->next = node;
            cur->prev = node;
            
            size++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        Node* cur = getNode(index);
        if (!cur) return;
        
        if (0 == index) {            
            //删除头节点
            head = head->next;
            if (head)
                head->prev = NULL;
        } else if (size - 1 == index) {
            //删除尾节点
            tail = tail->prev;
            if (tail)
                tail->next = NULL;
        } else {
            //删除中间节点
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }
        
        delete cur;
        size--;
    }

private:
    struct Node
    {
        int val;
        Node* prev;
        Node* next;
        Node(int v) : val(v), prev(NULL), next(NULL) 
        {            
        }
    };
    
    Node* getNode(int index) {
        if (index >= size) return NULL;
        
        Node* cur = NULL;
        if (2 * index <= size) {
            cur = head;
            while (index--) {
                cur = cur->next;
            }
        }
        else {
            cur = tail;
            index = size - index - 1;
            while (index--) {
                cur = cur->prev;
            }
        }
        return cur;
    }
    
    Node* head;
    Node* tail;
    int size;
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