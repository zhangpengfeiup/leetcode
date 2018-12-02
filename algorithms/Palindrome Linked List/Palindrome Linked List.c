#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    struct ListNode *p,*q;
    p = (struct ListNode *)malloc(len);
    p->next = NULL;
    head = p;

    if (num <= 0) {
        return head;
    }

    printf("请输入第1个节点的value \n");
    scanf("%d",&p->val);

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

/**
 *  In the problem,i think it should use the two pointer of slow and fast pointer. And a problem i don't think out it,which is
 *  when the num of pointer is odd number,the pointer how to go.
 *  From look others code,I find we can reverse the list from the half pointer of the list. for example if the list is 1->2->3->2->1
 *  From 3 we reverse the list,the list will change 1->2->3->1->2
 *  we can compare from 3->next is 1->2 to the head pointer of 1->2,because the num is equal.so it is can judge it is palindrome.
 */
bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next) {
        return true;
    }
    struct ListNode *slow,*fast,*last,*pre;
    slow = fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    last = slow->next;
    pre = head;

    //reverse the end half of list
    while(last->next) {
        struct ListNode *tmp;
        tmp = last->next;
        last->next = tmp->next;
        tmp->next = slow->next;
        slow->next = tmp;
    }

    while(slow->next) {
        slow = slow->next;
        if (slow->val != pre->val) return false;
        pre = pre->next;
    }
    return true;
}

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
    bool flag;
    flag = isPalindrome(head);
    if (flag) {
        printf("it is palindrome\n");
    }else {
        printf("it is not palindrome\n");
    }
    //printList(head);

    return 0;
}
