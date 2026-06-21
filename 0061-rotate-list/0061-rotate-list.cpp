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
    ListNode* findnthNode(ListNode* temp,int k){
        int cnt=1;
        while(temp!=NULL){
            if(cnt==k) return temp;
            cnt++;
            temp=temp->next;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0||head==NULL) return head;
        int len=1;
        ListNode* tailNode=head;
        while(tailNode->next!=NULL){
            len++;
            tailNode=tailNode->next;
        }
        k=k%len;
        if(k==0) return head;
        tailNode->next=head;
        ListNode* newTail=findnthNode(head,len-k);
        head=newTail->next;
        newTail->next=NULL;
        return head;
    }
};