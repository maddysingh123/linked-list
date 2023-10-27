class Solution {
public:
int findLength(ListNode *head){
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        int len=findLength(head);
        if(len<k){
            return head;
        }
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *forward=NULL;
        int count=0;
        while(count<k && curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }
        if(forward!=NULL){
            head->next=reverseKGroup(curr,k);
        }
        return prev;
    }
};
