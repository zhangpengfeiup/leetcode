#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct StackNode{
    char data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct {
    LinkStackPtr top;
    int count;
}LinkStack;

bool InitStack(LinkStack *S) {
    S->top = (LinkStackPtr)malloc(sizeof(StackNode));
    S->top = NULL;
    S->count = 0;
    return true;
}


bool StackEmpty(LinkStack S) {
    if (S.count == 0) {
        return true;
    }else {
        return false;
    }
}

bool Push(LinkStack *s,char c) {
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    p->data = c;
    p->next = s->top;
    s->count++;
    s->top = p;
    return true;
}

bool Pop(LinkStack *s) {
    if (s->count == 0) {
        return false;
    }
    LinkStackPtr p;
    p = s->top;
    s->top = s->top->next;
    free(p);
    s->count--;
    return true;
}

bool GetTop(LinkStack s,char *c) {
    if (s.top == 0) {
        *c = 'a';
        return false;
    }
    *c = s.top->data;
    return true;
}

/*
 * At first sight,you will think the code is much.But the code of main idea is use the link stack.
 * Yeah,use the link implement the stack.
 */

bool isValid(char* s) {
    int len,i;
    char val,c;
    len = strlen(s);
    LinkStack S;
    InitStack(&S);
    for (i=0;i<len;i++) {
        c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            Push(&S,c);
        }
        if (c == ')') {
            GetTop(S,&val);
            if (val == '(') {
                Pop(&S);
            }else{
                Push(&S,c);
            }

        }
        if (c == ']') {
            GetTop(S,&val);
            if (val == '[') {
                Pop(&S);
            }else{
                Push(&S,c);
            }
        }
        if (c == '}') {
             GetTop(S,&val);
            if (val == '{') {
                Pop(&S);
            }else{
                Push(&S,c);
            }
        }
    }
    if (StackEmpty(S)) {
        return true;
    }else {
        return false;
    }

}

int main() {
    char greeting[] = {'(',')','[','\0'};
    bool ret;
    ret = isValid(greeting);
    if (ret) {
        printf("ok \n");
    }else {
        printf("fail\n");
    }
    printf("Greeting message: %s\n" ,greeting);
}

