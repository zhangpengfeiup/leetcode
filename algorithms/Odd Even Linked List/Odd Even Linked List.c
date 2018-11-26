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
  this is my answer, i use the variable i to judge the position is even node or odd node.
  the difficult is the p is change,because we change the position, the p position will change
  int the begin,i find the i variable from 1 to 8, the node all is 5,why is 8?
  I find the p change position,so we need to notice the p node change. and pre node change.
  in the code is
  if () {
     p = pre->next
  }else {
    pre = p;
    p = p->next;
  }

  if you do not understand it.you can draw the node change in the paper.

    in the answer,not i variable,it use pointer finish it. you can see it in the below.
*/
struct ListNode* oddEvenList(struct ListNode* head) {
    if (!head || !head->next || !head->next->next) {
        return head;
    }
    int i=1;
    struct ListNode *pre,*tmp,*p;
    p = head;
    tmp = head;
    while(p) {

        printf("%d\n",i);

        if (i>1 && i % 2 == 1) {
            //printf("%d\n",p->val);
            struct ListNode *q;
            q = p;
            pre->next = q->next;
            q->next = tmp->next;
            tmp->next = q;
            tmp = tmp->next;


            p = pre->next;
        } else {
            pre = p;
           p = p->next;
        }

        i++;
    }

    return head;
}

/*
struct ListNode* oddEvenList(struct ListNode* head) {
    if (!head || !head->next || !head->next->next) {
        return head;
    }
    struct ListNode *p,*q,*insert;
    insert = head;
    p = head->next;
    while(p && p->next) {
        q = p->next;
        //remove the q
        p->next = q->next;
        //insert the q into the correct space
        q->next = insert->next;
        insert->next = q;
        insert = insert->next;

        p = p->next;
    }
    return head;
}

*/
int main() {
    struct ListNode *head;
    head = createList();
    head = oddEvenList(head);


   printNode(head);

    return 0;
}
