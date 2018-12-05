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

/*
 * In the beginning, i write the code can't run.because i use the new list p,and p->list = head,
 * in the new list of p to find where location to insert.It is wrong.We need a new list,and then delete from the old list of head and
 * find the location from the new list of p.then insert it.
 * Beside,when use the c language new a list,we need put the p->next = null,if we lost it.it will can't find where is p.
 */

struct ListNode* insertionSortList(struct ListNode *head) {
    if (!head || !head->next) {
        return head;
    }

    struct ListNode *p,*cur;
    p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->next = NULL;

    while(head) {
        struct ListNode *tmp = head->next;

        cur = p;
        //find insert location
        while(cur->next && cur->next->val <= head->val) {
            cur = cur->next;
        }
        head->next = cur->next;
        cur->next = head;

        head = tmp;
    }

    return p->next;
}




int main() {
    struct ListNode *head;
    head = createList();



    head = insertionSortList(head);
     printNode(head);
    return 0;
}
