#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

    p->next = NULL;
    head = p;
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



 /*
  * In the beginning, I think if the list is a cycle. when the list move the end of list, the next is head.
  * So i can use a pointer point to the head of list. move anther pointer from the beginning if when they are equal, the list is cycle.
  * if not equal,the pointer may move the last of list is NULL.so it is not a cycle. But submit it,it runtime out.
  *
  * So we should use the slow pointer and fast pointer to finish it.
  */
bool hasCycle(struct ListNode *head) {
    if (!head || !head->next) {
        return false;
    }
    struct ListNode *slow,*fast;
    slow = fast = head;
    while(slow->next && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}


int main() {
    struct ListNode *head;
    head = createList();
    bool flag;
    flag = hasCycle(head);
    if (flag) {
        printf("it is cycle\n");
    }else {
        printf("no cycle\n");
    }
    return 0;
}
