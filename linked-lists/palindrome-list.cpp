/*

Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

    Expected solution is linear in time and constant in space.

For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.

*/

int Solution::lPalin(ListNode* A){
    
    ListNode *s=A,*f=A,*prev;
    
    while(f!=NULL && f->next!=NULL){
        prev=s;
        s=s->next;
        f=f->next->next;
    }
    
    if(f!=NULL){
        prev=s;
        s=s->next;
    }
    
    //s points to something that you need to reverse;
    prev->next=NULL;
    ListNode *temp=s,*beta=NULL,*baap=NULL;
    while(s!=NULL){
        baap=s->next;
        s->next=beta;
        beta=s;
        s=baap;
    }
    temp=beta;
    ListNode *head=A,*temp1=temp,*head1=A;
    
    
    while(temp!=NULL && head!=NULL){
        if(temp->val==head->val){
            temp=temp->next;
            head=head->next;
        }
        else{
            return 0; 
        }
    }
   
    return 1;
}
