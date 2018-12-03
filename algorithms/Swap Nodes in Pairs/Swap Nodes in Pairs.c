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
    printf("请输入将要输入节点的个数");
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    struct ListNode *p,*cur;
    p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p->next = head;
    cur = p;
    while(cur->next && cur->next->next) {
        struct ListNode *tmp;
        tmp = cur->next->next;
        //you should attention here is cur->next->next,because you delete cur->next->next and cur->next->next = tmp->next
        cur->next->next = tmp->next;
        tmp->next = cur->next;
        cur->next = tmp;

        cur = cur->next->next;
    }
    return p->next;
}



int main() {
    struct ListNode *head;
    head = createList();

    head = swapPairs(head);
    printNode(head);
    return 0;
}
