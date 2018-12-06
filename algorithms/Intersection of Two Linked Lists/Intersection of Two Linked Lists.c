#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/*
* create the list and return the head node
*/
struct ListNode* createList() {
    struct ListNode *head,*p,*q;
    int len,n,num,i;
    printf("请输入将要输入节点的  个数");
    scanf("%d",&n);
    len = sizeof(struct ListNode);
    //malloc the node
    p = (struct ListNode *)malloc(len);
    printf("请输入第 1个节点的值");
    scanf("%d",&num);
    p->val = num;
    p->next = NULL;
    head = p;
    for (i=1;i<n;i++) {
        printf("请输入第 %d 节点的值",i+1);
        q = (struct ListNode *)malloc(len);
        scanf("%d",&num);
        q->val = num;
        p->next = q;
        p = q;
    }
    // attention not forget the last node is null,if forget the loop will not stop.
    p->next = NULL;
    return head;
}


void printNode(struct ListNode *head) {
    while(head) {
        printf("%d ",head->val);
        head = head->next;
    }
}

// 756ms emmmm~
/*
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (!headA || !headB) {
        return NULL;
    }
    struct ListNode *b;
    while(headA) {
        b = headB;
        while(b) {
            if (b->val == headA->val) {
                return b;
            } else {
                b = b->next;
            }
        }
        headA = headA->next;
    }
    return NULL;
}
*/

/*
 *  why we write the behind word.because pa and pb run the same distance.
 *  if they have the intersection, they will meet one node.
 *  if not,they will both run the null.so they will equal in the last.
 *
 *  I am aware of the importance of math for the code deeply.
 *  So the math is very useful. We should learn and use it flexibly.
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
   if (!headA || !headB) {
      return NULL;
   }
   struct ListNode *pa,*pb;
   pa = headA;
   pb = headB;
   while(pa != pb) {
        pa = pa ? pa->next : headB;
        pb = pb? pb->next : headA;
   }
   return pa;
}


int main() {
    struct ListNode *one,*two,*intersect;
    one = createList();
    two = createList();
    intersect = getIntersectionNode(one,two);



     printNode(intersect);
    return 0;
}
