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



// you should now,we change the data link pointer so the head position will change
// so we need a new link to save the after change link

struct ListNode* partition(struct ListNode* head, int x) {
    // empty node or one node
    if ( !head || !head->next) {
        return head;
    }
    //find >x node position
    struct ListNode *cur,*pre,*p;
    //why not pre = head->next ?? because you want to assign value to the pre
    // if you do not malloc the size,he can not find where put the pre->next

    pre = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = (struct ListNode *)malloc(sizeof(struct ListNode));

    pre->next = head;
    p = pre;

    cur = head;


    while(pre->next && pre->next->val < x) {
        pre=pre->next;
    }

    // the p->next is val>x of node
    cur = pre;

    while(cur->next) {
        if (cur->next->val < x) {

            struct ListNode *tmp;

            // delete the node tmp, and move the cur
            tmp = cur->next;  //1
            cur->next = tmp->next;

            // insert the node tmp after the pre
            tmp->next = pre->next;
            pre->next = tmp;

            pre = pre->next;

        } else {
            //printf("%d\n",cur->next->val);
            cur = cur->next;
        }

    }
    return p->next;

}

//the other method to solve the problem,put two list,in the last,merge it.
/*
	struct ListNode* partition(struct ListNode* head, int x) {
      // empty node or one node
    if ( !head || !head->next) {
        return head;
    }
    struct ListNode *left,*right,*lhead,*rhead;
    // you should know the left and the right is the first address.
    // and the struct list node pointer is will change but the address can not change
    left = (struct ListNode *)malloc(sizeof(struct ListNode));
    right = (struct ListNode *)malloc(sizeof(struct ListNode));

    lhead = left;
    rhead = right;

    left->next = NULL;
    right->next = NULL;
    while(head) {
        struct ListNode *temp = head->next;
        if (head->val < x) {
            lhead->next = head;
            // you need notice the left->next = head
            // and left->next->next = head->next; so we need a temporary variable save the head->next
            head->next=NULL;
            lhead = lhead->next;
        } else {
            rhead->next = head;
            head->next=NULL;
            rhead=rhead->next;
        }
        head = temp;
    }



    lhead->next=right->next;

    return left->next;
	}
*/



int main() {
    struct ListNode *head;
    head = createList();

    head = partition(head,3);
    printNode(head);
    return 0;
}
