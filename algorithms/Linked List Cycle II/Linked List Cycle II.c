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

    // if you want the list is cycle, you can change the code p->next = head.
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
 * the code can not use the function createList to test,you can watch the code
 * In the beginning, I understand the cycle is from head to tail and the tail list point to the head list
 * Otherwise, the cycle can 1-2-3-4-5 5->2  so the cycle is 2->3->4->5.
 * Also, why we find where the cycle meet.We need put the slow pointer point to the head?
 * The problem you can refer to http://www.cnblogs.com/hiddenfox/p/3408931.html or https://blog.csdn.net/willduan1/article/details/50938210
 * And the pointer can access,you should judge it. in the problem the fast pointer run quickly than the slow.
 * so you only need judge the fast pointer is null.
 * From the problem, I find the think the problem clearly and know where is most likely to go wrong. And then to code it. You will work more efficient.
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow,*fast;
    slow = fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
           break;
        }
    }
    //if not cycle
    if (!fast || !fast->next) {
        return NULL;
    }

    slow = head;
    while(slow != fast && slow->next && fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}



int main() {
    struct ListNode *head;
    head = createList();
    head = detectCycle(head);
    printNode(head);
}
