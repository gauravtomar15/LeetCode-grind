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
    ListNode* findeNode(ListNode* temp , int k){
        int count =1;
        while(temp!=NULL){
            if(count==k) return temp;
            temp = temp->next;
            count++;
        }
        return temp;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k==0) return head;
        int len = 1;
        ListNode* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
            len += 1;
        }
        if(k%len == 0) return head;
        k = k%len;
        tail->next = head;

        ListNode* newlastNode = findeNode(head , len-k);
        head = newlastNode->next;
        newlastNode->next = NULL;
        return head;
        
    }
};