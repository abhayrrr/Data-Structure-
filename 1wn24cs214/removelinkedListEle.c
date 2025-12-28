/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *temp,*follow;
    if (head==NULL)
        printf("Linked List is already empty\n");
    else{
        temp=head;
        while(temp!=NULL){
            if (temp->val==val){
                if(temp==head){
                    head = head->next;
                    free(temp);
                    temp=head;
                }
                else{
                    follow->next=temp->next;
                    free(temp);
                    temp=follow->next;
                }
            }
            else{
                follow=temp;
                temp=temp->next;
            }
        }
    }
    return head;
    
}