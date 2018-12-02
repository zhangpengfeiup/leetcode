#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* createList(struct ListNode *head)
{
    int num,len;
    len = sizeof(struct ListNode);
    printf("请输入想要创建链表的节点数\n");
    scanf("%d",&num);
    if (num <= 0) {
        return head;
    }
    struct ListNode *p,*q;
    p = (struct ListNode *)malloc(len);
    printf("请输入第1个节点的value \n");
    scanf("%d",&p->val);
    p->next = NULL;
    head = p;
    for (int i=1;i<num;i++) {
       q = (struct ListNode *)malloc(len);
       printf("请输入第 %d 个节点的value \n",i);
       scanf("%d",&q->val);
       q->next = NULL;
       p->next = q;
       p = p->next;
    }
    p->next = NULL;
    return head;
}


struct ListNode* mergeList(struct ListNode *l1,struct ListNode *l2) {
    struct ListNode *p = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *cur;
    p->next = NULL;
    cur = p;
    if (!l1) {
        cur->next = l2;
        return p->next;
    }

    if (!l2) {
        cur->next = l1;
        return p->next;
    }
    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        }else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    if (l1) {
        cur->next = l1;
    }
    if (l2) {
        cur->next = l2;
    }
    return p->next;
};

/*
struct ListNode* mergeList(struct ListNode *l1,struct ListNode *l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
        l1->next = mergeList(l1->next,l2);
        return l1;
    } else {
        l2->next = mergeList(l2->next,l1);
        return l2;
    }
}
*/

// Refer to the grandyang http://www.cnblogs.com/grandyang/p/4249905.html
// use the fast and slow point to split the halt of the list
struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    struct ListNode *fast,*pre,*slow;
    fast = pre = slow = head;

    while(fast && fast->next) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = NULL;
    return mergeList(sortList(head),sortList(slow));
};

void printList(struct ListNode *head)
{
    while (head) {
        printf("%d ",head->val);
        head = head->next;
    }
}

int main()
{
    struct ListNode *head;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head = createList(head);
    head = sortList(head);
    printList(head);

    return 0;
}
