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
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }

        Node* curr = head;
        
        // insert new node in between the original node

        while(curr){
            Node* currNext = curr->next;  // store krega B
            curr->next = new Node(curr->val); // A->B  kyuki yha ab hogya hoga A-> x-> B
            curr->next->next = currNext;

            curr = currNext; 
        } 
        // deep copy of random pointer

        curr = head;
        while(curr){
            if(curr->random==NULL){
                curr->next->random = NULL;
            } else{
                curr->next->random = curr->random->next;
            }
            curr  = curr->next->next;
        }

        // separate the both LinkedList
        Node* newHead = head->next;
        Node* newCurr = newHead;
        curr = head;

        while(curr && newCurr){
            curr->next = curr->next == NULL ? NULL : curr->next->next;
            newCurr->next = newCurr->next == NULL ? NULL : newCurr->next->next;

            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
};