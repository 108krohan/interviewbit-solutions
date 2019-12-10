/*

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

*/

ListNode* swap(ListNode* next1, ListNode* next2) {
    next1->next = next2->next;
    next2->next = next1;
    return next2;
}
ListNode* Solution::swapPairs(ListNode* head){
    ListNode* start = new ListNode(0); //make head no longer a special case
    start->next = head;

    ListNode *cur = start;
    while (cur->next != NULL && cur->next->next != NULL) {
        cur->next = swap(cur->next, cur->next->next);
        cur = cur->next->next;
    }
    return start->next;
}
