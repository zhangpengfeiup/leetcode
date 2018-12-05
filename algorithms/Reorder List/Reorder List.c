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
   len = sizeof(struct ListNode);
    //malloc the node
    p = (struct ListNode *)malloc(len);
    p->next = NULL;
    head = p;
    printf("请输入将要输入节点的个数");
    scanf("%d",&n);
    if (n <= 0) {
        return head;
    }
    printf("请输入第 1个节点的值");
    scanf("%d",&num);
    p->val = num;

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


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 // you can use the printNode debug the list change
void reorderList(struct ListNode* head) {
    if (!head || !head->next || !head->next->next) {
        return;
    }

    struct ListNode *slow,*fast,*cur,*p;
    p = (struct ListNode *) malloc(sizeof(struct ListNode));
    p->next = head;
    cur = p;
    slow = fast= head;
    // find the middle of the list. separate the list to two list.
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *mid;
    mid = slow->next;
    struct ListNode *last,*pre;
    last = mid;
   //  printNode(last);
    slow->next = NULL;


    pre = NULL;
    // reverse the second half list,and pre is the head
    while (last) {
        struct ListNode *next = last->next;
        last->next = pre;
        pre = last;
        last = next;
    }

    struct ListNode *first = head;

    // merge the first and pre to list p
    while (first && pre) {
        cur->next = first;
        // attention it
        first = first->next;

        cur = cur->next;

        cur->next = pre;
        // attention it
        pre = pre->next;
        cur = cur->next;
    }
    
    if (first) {
        cur->next = first;
    }
    if (pre) {
        cur->next = pre;
    }
    head = p->next;
    //printNode(head);
}

/*
void reorderList(struct ListNode* head) {
    if (!head || !head->next || !head->next->next) {
        return;
    }
    struct ListNode *slow,*fast;
    slow = fast = head;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *mid;
    // mid is the head of second half
    mid = slow->next;
    slow->next = NULL;
   // printNode(mid);
    struct ListNode *last;
    last = mid;
    struct ListNode *pre = NULL;
    //reverse the second half
    while(last) {
        struct ListNode *next = last->next;
        last->next = pre;
        pre = last;
        last = next;
    }
    //printNode(head);
   // printf("00");
   // printNode(pre);
  //  printf("00");
    while (head && pre) {
        struct ListNode *next = head->next;
        head->next = pre;
        pre = pre->next;
        head->next->next = next;
        head = next;
    }
}
*/

int main() {
    struct ListNode *head;
    head = createList();

    reorderList(head);

    return 0;
}
