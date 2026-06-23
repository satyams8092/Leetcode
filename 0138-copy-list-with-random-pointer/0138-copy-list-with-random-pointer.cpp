/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertInBetween(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* copyNode = new Node (temp->val);
            copyNode->next=temp->next;
            temp->next=copyNode;
            temp=temp->next->next;        
        }
    }

    void connectRamdomPtr(Node* head){
        Node*temp=head;
        while(temp!=NULL){
            Node* dummyNode=temp->next;
            if(temp->random){
                dummyNode->random=temp->random->next;
            }else{
                dummyNode->random=NULL;
            }
            temp=temp->next->next;
        }
    }

    Node* getCopyList(Node* head){
        Node* dummyNode=new Node(-1);
        Node* res=dummyNode;
        Node* temp=head;
        while(temp!=NULL){
            res->next=temp->next;
            temp->next=temp->next->next;
            temp=temp->next;
            res=res->next;
        }
        return dummyNode->next;
    }

    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        insertInBetween(head);
        connectRamdomPtr(head);
        return getCopyList(head);
    }
};