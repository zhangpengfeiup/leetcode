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
 * Refer to Grandyang http://www.cnblogs.com/grandyang/p/4306611.html#commentform
 * I think the reverse is so funny.And it need we understand the link pointer clearly.
 * In the problem,we need know we use the pre->next to make the pointer back on the linklist.
 * And we use the last = cur->next to save the reverseList head pointer. in 1->2->3->4->5->NULL,cur->next is save 2
 * After understand it.Find the linklist is so funny. Also, We need deal it carefully.
 * Beside, I find that when i write the code and draw the flow of the problem in the picture. I understand it clearly.
 * So,in the future,I will draw the flow of problem and write the code in the paper.After know it carefully. Code to do it.
 */

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if (!head) {
        return head;
    }
    struct ListNode *dummy;
    dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *pre,*first,*cur,*last;
    cur = dummy;
    int i;
    for(i=0;i<m-1;i++) {
        cur = cur->next;
    }
    pre = cur;
    last = cur->next;

    for (i=m;i<=n;i++) {
        cur = pre->next;
        pre->next = cur->next;
        cur->next = first;
        first = cur;
    }
    cur = pre->next;
    pre->next = first;
    last->next = cur;
    return dummy->next;
}




int main() {
    struct ListNode *head;
    head = createList();



    head = reverseBetween(head,2,4);
     printNode(head);
    return 0;
}
