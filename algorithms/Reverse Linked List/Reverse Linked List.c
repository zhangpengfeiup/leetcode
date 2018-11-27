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
    recursive

    In the beginning, I can't think recursive it clearly.
    So i find i don't understand the recursive.
    I learn from http://www.cnblogs.com/grandyang/p/4478820.html
    After, I draw the change in the paper.

    when head = reverseList(5->next) because 5->next is null so return head
    then head = reverseList(4->next) because 4->next is 5,equal p->next = 5,p->next->next = p,and p->next = null  is 5->4->null
    head = reverseList(3->next) equal 4->3->null
    head = reverseList(2->next) equal 3->2->null
    head = reverseList(1->next) equal 2->1->null

    there the reverseList is ok.

struct ListNode* reverseList(struct ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    struct ListNode *p;
    p = head;
    head = reverseList(p->next);
    p->next->next = p;
    p->next = NULL;
    return head;
}

*/

/*
    iterative

    I understand iterative the reverse Linked list is insert the head of new list
*/
struct ListNode* reverseList(struct ListNode* head) {
    if (!head) {
        return head;
    }
    struct ListNode *n = (struct ListNode *)malloc(sizeof(struct ListNode));
    n->next = head;

    struct ListNode *cur;
    cur = head;
    //equal insert the node into the n list head
    while(cur->next) {
        struct ListNode *tmp;
        tmp = cur->next;
        // assign value to cur->next
        cur->next = tmp->next;
        tmp->next = n->next;
        n->next = tmp;
    }
    return n->next;
}




int main() {
    struct ListNode *head;
    head = createList();



    head = reverseList(head);
     printNode(head);
    return 0;
}
