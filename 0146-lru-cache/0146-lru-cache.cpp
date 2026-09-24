
class LRUCache {
    struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k,int v) : key(k),value(v),prev(nullptr),next(nullptr) {}
    };
    int cap;
    unordered_map<int,Node*> mpp;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

public:
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void deleteNode(Node* node){
        Node* prevNode=node->prev;
        Node* nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }

    void insertAfterHead(Node* node){
        Node* temp=head->next;
        node->next=temp;
        node->prev=head;
        temp->prev=node;
        head->next=node;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            deleteNode(node);
            insertAfterHead(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            node->value=value;
            deleteNode(node);
            insertAfterHead(node);
            return;
        }else if(mpp.size()==cap){
            Node *node= tail->prev;
            int key=node->key;
            deleteNode(node);
            mpp.erase(key);
            delete node;
        }
        Node* newNode = new Node(key,value);
        insertAfterHead(newNode);
        mpp[key]=newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */