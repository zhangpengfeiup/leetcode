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

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) {
        return head;
    }
    struct ListNode *p;
    p = head;
    // here we need ensure the p and the p->next is true
    while(p && p->next) {
        //if the val equal the next val we need jump it or we need make the pointer back
        if (p->val == p->next->val) {
            p->next = p->next->next;
        }else {
         p = p->next;
        }
      }

    return head;
}


int main() {
    struct ListNode *head;
    head = createList();

    head = deleteDuplicates(head);
    printNode(head);

    return 0;
}

