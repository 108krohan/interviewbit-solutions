/*

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

    Note:
    Given m, n satisfy the following condition:
    1 ≤ m ≤ n ≤ length of list.

    Note 2:
    Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question. 

*/
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    
    int i=1;
    
    ListNode *start, *end, *prev, *next;
    
    ListNode *temp=new ListNode(0);
    
    temp->next=A;
    
    ListNode *curr=temp;
    
    while(i != (B)){
        curr=curr->next;
        i++;
    }
    
    
    start=curr;
    end=curr->next;
    curr=curr->next;
    prev=NULL;
    
    while(i != (C+1)){
        next=curr->next;
        curr->next=prev;
        
        prev=curr;
        curr=next;
        
        i++;
    }
    
    start->next=prev;
    end->next=curr;
    
    return temp->next;
    
}
