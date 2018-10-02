/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.
Subscribe to see which companies asked this question
Tags: Hash Table Linked List
*/

//Code:
//Code 1: 处理很长的链表时，会产生Runtime Error
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
  class Solution {
 public:
     RandomListNode *copyRandomList(RandomListNode *head) {
         if (head == nullptr) return head;
         RandomListNode* pCur = head;

         //Copy the RandomListNode
         // 1-2-3-4-5  ==> 1-1-2-2-3-3-4-4-5-5
         while (pCur != nullptr)
         {
             RandomListNode* pNext = pCur->next;
             pCur->next = new RandomListNode(pCur->label);
             pCur->next->next = pNext;
             pCur = pNext;
         }

         //Add the random value for new RandomListNode
         pCur = head;
         while (pCur != nullptr)
         {
             RandomListNode* pNext = pCur->next->next;
             if (pCur->random == nullptr)
                 pCur->next->random = nullptr;
             else
                 pCur->next->random = pCur->random->next;
             pCur = pNext;
         }

         //split the list to two lists
         RandomListNode* head2 = head->next;
         RandomListNode* pCur2 = head2;
         pCur = head;
         while (pCur2 != nullptr && pCur2->next != nullptr)
         {
             pCur = pCur->next->next;
             pCur2 = pCur2->next->next;
             pCur = pCur->next;
             pCur2 = pCur2->next;
         }

         pCur = nullptr;
         return head2;
     }
 };


//Code 2:
class Solution {
public:
     RandomListNode *copyRandomList(RandomListNode *head) {
         if (head == nullptr) return head;
         RandomListNode dummyHead(0);
         RandomListNode* p2 = &dummyHead;
         RandomListNode* p1 = head;

         //Copy the RandomListNode
         for (; p1 != nullptr; p1 = p1->next)
         {
             p2->next = new RandomListNode(p1->label);
             p2 = p2->next;
         }

         //Add the random value for new RandomListNode
         p1 = head;
         p2 = dummyHead.next;
         while (p1 != nullptr)
         {
             if (p1->random == nullptr)
                 p2->random = nullptr;
             else
             {
                 RandomListNode* pRandom2 = dummyHead.next;
                 RandomListNode* pRandom1 = head;
                 while (pRandom1 != p1->random)
                 {
                     pRandom1 = pRandom1->next;
                     pRandom2 = pRandom2->next;
                 }
                 p2->random = pRandom2;
             }
             
             p1 = p1->next;
             p2 = p2->next;
         }
         return dummyHead.next;
     }
};
