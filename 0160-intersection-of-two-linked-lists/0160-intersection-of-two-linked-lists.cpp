/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int length(ListNode* head) {
        int cnt = 0;
        while (head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = length(headA);
        int lenB = length(headB);
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;

        if(lenA>lenB){
            for(int i =0; i<lenA-lenB; i++){
                ptr1 = ptr1->next;
            }

        } else{
            for(int i =0; i<lenB-lenA; i++){
                ptr2 = ptr2->next;
            }
        }
        while(ptr1 && ptr2){
            if(ptr1==ptr2) return ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return NULL;
    }
};