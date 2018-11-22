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

struct ListNode* deleteDuplicates(struct ListNode* head) {
    int i=0;
    struct ListNode *p,*q;
    p = head;
    while (p) {
        while ( p && p->next && p->val == p->next->val && i == 0) {
            q=p->next;
            // the q is in the while loop,so you need ensure the q is available
            while(q && p->val == q->val) {
                q=q->next;
            }
            //find the q and you need change the head
            head = p = q;
        }

        i++;
    // you should ensure the p and p->next && p->next->next is available
    while (p&& p->next && p->next->next && p->next->val == p->next->next->val){
                q = p->next->next;
                //find the

                 // the q is in the while loop,so you need ensure the q is available
                while(q && q->val==p->next->val) {
                    q = q->next;
                }
                p->next = q;
        }

        // the p may be is null is here,so you need ensure is not null.
        if (p) {
            p=p->next;
        }else {
            return head;
        }

    }
    return head;
}

/*
After i have submited,i saw the code from the answer is the code new a new list and assign the value.
you can learn from it. the code is so short and look is very good.

struct ListNode* deleteDuplicates2(struct ListNode* head) {
    struct ListNode* t1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* res=t1,*t2=head;
    t1->next = head;
    int f,v;
    while(t2) {
        f = 0;
        v = t2->val;
        while(t2->next && t2->next->val == v) {
            t2 = t2->next;
            f = 1;
        }
        if (f==0) {
            t1 = t1->next;
        }else {
            t1->next = t2->next;
        }
        t2 = t2->next;
    }
    return res->next;
}
*/



int main() {
    struct ListNode *head;
    head = createList();

    head = deleteDuplicates(head);
    printNode(head);

    return 0;
}

