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


/*
 * remove the equal val from the list
 * in the problem, I forget the when the list is one number,and we want delete the one.
 * so the if can not contain the if(!head || !head->next) { return head}
 * when we meet the problem,if we have done it and know how to do it.
 * But we can't do it success sometimes.so we need keep patience.
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (!head) {
        return head;
    }
    struct ListNode *p,*cur;
    p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->next = head;
    cur = p;
    while (cur->next) {
        if (cur->next->val == val) {
            struct ListNode *tmp;
            tmp = cur->next;
            cur->next = tmp->next;
        }else {
            cur = cur->next;
        }
    }
    return p->next;
}





int main() {
    struct ListNode *head;
    head = createList();
    int val;
    printf("请输入要删除的值\n");
    scanf("%d",&val);
    head = removeElements(head, val);
     printNode(head);
    return 0;
}
