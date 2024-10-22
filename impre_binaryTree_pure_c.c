#include <stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* l;
    struct node* r;
};
typedef struct node* Tree;
Tree createTree(int data) {
    Tree emptynode = (Tree)malloc(sizeof(struct node));
    emptynode->data = data;
    emptynode->l = NULL;
    emptynode->r = NULL;
    return emptynode;
}
void push(Tree node, int data) {
    if(node == NULL) return;
    if(data < node->data) {
        if(node->l == NULL) node->l = createTree(data);
        else push(node->l,data);
    }
    else if(data > node->data){
        if(node->r == NULL) node->r = createTree(data);
        else push(node->r,data);
    }
    else printf("data is alredy in tree");
}
void DFS(Tree node) {
    if (node != NULL) {
        printf("%d  ,", node->data);
        DFS(node->l);
        DFS(node->r);
    }
}
Tree tree(int data_root, int data_left, int data_right){
    Tree root, left, right;
    root = createTree(data_root);
    root->l = createTree(data_left);;
    root->r = createTree(data_right);
}
int main() {
    Tree a = tree(2, 4, 5);
    push(a, 10);
    push(a, 20);
    DFS(a);
    return 0;
}