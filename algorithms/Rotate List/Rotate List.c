#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head) {
        return head;
    }

   struct ListNode *p,*q,*r,*l;
    l = head;
    int num=0;
    while(l) {
        l=l->next;
        num++;
    }
    // if k is so large,so we should decrease the for loop of k.
    k = k % num;
    //r指向头结点
    int i;
    for(i=0;i<k;i++) {
        r = head;
        //找到倒数第二个结点
        if (head->next){
             while(head->next->next) {
            head=head->next;
            }
            p=head;
            //倒数第一个结点
            q=head->next;
            p->next = q->next; // q->next = NULL
            q->next=r;    //q->next = head
            head = q;
        }
    }
    return head;
}

//init the list
struct ListNode* CreateListTail()
{
    //定义指向结构体 的指针
    struct ListNode *head,*p1,*p2;
    int n;
    printf("scanf the num n");
    scanf("%d",&n);
    //一开始头指针指向空

    int len = sizeof(struct ListNode);
    //定义p1的指向
    p1 = (struct ListNode *)malloc(len);

    scanf("%d",&p1->val);
    p1->next = NULL;
    head = p1;
    int i;
    //p1结点一直后移，指向最后一个结点
    for(i=0;i<n-1;i++) {
        p2 = (struct ListNode *)malloc(len);

        scanf("%d",&p2->val);
        p1->next = p2;
        p1 = p2;
    }
    p1->next = NULL;
    return head;
}

void print(struct ListNode *head) {
    while(head) {
        printf("%d ",head->val);
        head=head->next;
    }
};



int main()
{
    //如何创建单链表呢
    struct ListNode *head;
    head = CreateListTail();
    head = rotateRight(head,200000);
    print(head);
    return 0;
}
