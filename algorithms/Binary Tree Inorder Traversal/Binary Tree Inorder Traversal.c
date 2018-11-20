#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode A;

void create(struct TreeNode **T) {
    int data;
    scanf("%d",&data);
    if (data == 0) {
        *T = NULL;
    }else {
        //结构体指针
        *T = (struct TreeNode *)malloc(sizeof(A));
        (*T)->val=data;
        create(&(*T)->left);
        create(&(*T)->right);
    }
}

int treesize(struct TreeNode* root){
    if(root==NULL){
        return 0;
    }else{
        return (treesize(root->left)+treesize(root->right)+1);
    }
}


void inorder(struct TreeNode* root,int *returnSize,int *arr) {
    if (root == NULL) {
        return NULL;
    }
    //给returnSize分配空间
    inorder(root->left,returnSize,arr);
    (*returnSize)++;
    arr[(*returnSize)-1] = root->val;
    inorder(root->right,returnSize,arr);
}

int *inorderTraversal(struct TreeNode* root,int* returnSize) {
    *returnSize=0;
    int size;
    size = treesize(root);
    int *arr = (int*)malloc((size+1)*sizeof(int));
    inorder(root,returnSize,arr);
    return arr;
}

//From this problem,i find the c is so funny. and I do not know is su much.
//And the tree is very useful dataStructure.So we need learn it more.and know how to use it efficient.

int main()
{
    struct TreeNode* T;
    create(&T);
    int n=0;
    inorderTraversal(T,&n);
    printf("%d",n);
    return 0;
}
