class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        if(head==NULL) return NULL;
        int n = 0;
        while(temp){
            n++;
            temp = temp->next;
        }
        k = k % n;
        if(k==0) return head;
        int trav = abs(k-n);
        
        temp = head;
        while(trav>1){
            temp = temp->next;
            trav--;
        }
        ListNode* newHead = temp->next;
        ListNode* temp2 = temp->next;
        temp->next = NULL;
        while(temp2->next!=NULL){
            temp2 = temp2->next;
        }
        temp2->next = head;
        return newHead;

    }
};