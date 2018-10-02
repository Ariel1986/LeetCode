/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
Tags: Linked List, Two Pointers
*/

/*思路
只需要从当前比x大的节点p1->next开始,找比x小的第一个节点p2->next，然后将该节点插到p1后面即可
*/

//Code:
ListNode* partition(ListNode* head, int x) {
    if(head == nullptr) return nullptr;
    ListNode dummyHead(0);
    ListNode* p1 = &dummyHead;
    p1->next = head;
    
    while(p1->next != nullptr)
    {
        if(p1->next->val >= x)
        {
            ListNode* p2 = p1->next;
            while(p2->next != nullptr)
            {
                if(p2->next->val < x)
                {
                    ListNode* ps = p2->next;
                    p2->next = ps->next;
                    ps->next = p1->next;
                    p1->next = ps;
                    break;
                }
                p2 = p2->next;
            }
                    
        }
        p1 = p1->next;
    }
    return dummyHead.next;
}
