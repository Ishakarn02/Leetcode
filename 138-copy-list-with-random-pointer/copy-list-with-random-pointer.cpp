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
void insertAtTail(Node* &head, Node* &tail, int d){
        
        Node* newNode = new Node(d);
        
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;

        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp -> val);
            temp = temp-> next;
        }

        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL){
             Node* _next = originalNode -> next;
             originalNode -> next = cloneNode;
             originalNode= _next;
             
             _next = cloneNode -> next;
             cloneNode -> next = originalNode;
             cloneNode = _next;
        }

        temp = head;
        while(temp != NULL){
            if(temp -> next != NULL){
                temp -> next -> random = temp -> random ? temp -> random -> next: temp -> random;
            }
            
            temp = temp -> next -> next;
        
        }
        
        // step4: revert changes in step 2
        originalNode = head;
        cloneNode = cloneHead;
        
         while(originalNode != NULL && cloneNode != NULL){
             
             originalNode -> next = cloneNode -> next;
             originalNode = originalNode -> next;
            
            if(originalNode != NULL){
             cloneNode -> next = originalNode -> next;
            }
             cloneNode = cloneNode -> next;
             
         }
        
        return cloneHead;
    }
};