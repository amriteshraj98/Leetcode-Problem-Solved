class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode* temp=head;
        ListNode* tail=NULL;
        if(head==NULL || head->next==NULL) return head;
        while(temp!=NULL){
            if(temp->next==NULL) tail=temp;
            n++;
            temp=temp->next;
        }
        temp=head;
        k=k%n;
        if(k==0) return head;
        for(int i=1;i<=n-k-1;i++){
            temp=temp->next;
        }
        tail->next=head;
        head=temp->next;
        temp->next=NULL;
        return head;
    
    }
};