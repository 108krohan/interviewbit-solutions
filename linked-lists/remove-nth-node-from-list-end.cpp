/*

Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

    Note:

        If n is greater than the size of the list, remove the first node of the list.

Try doing it using constant additional space.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    
    ListNode* temp = A; 
    while(B >= 1) {
        temp = temp->next; 
        if(temp == NULL) {
            return A->next; 
        }
        B -= 1;
    }
    ListNode* answer = A;
    while(temp->next != NULL) {
        temp = temp -> next; 
        answer = answer->next; 
    }
    if(answer->next != NULL) {
    answer->next = answer->next->next; 
    }
    return A;
}
