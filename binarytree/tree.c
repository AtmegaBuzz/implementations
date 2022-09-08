#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node *left;
    struct Node *right;
};


struct Tree{
    struct Node * root;
};

struct Node* createNode(int val){
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int insert(int val,struct Node *root){

    if (root==NULL){
        return 0;
    }

    // left 

    if (root->val==val){
        return 1; // already exist
    }

    if (root->val>val){
        if(insert(val,root->left)==0){
            root->left = createNode(val);
            return 1;
        }
    }
    else{
        if(insert(val,root->right)==0){
            root->right = createNode(val);
            return 1;
        }
    }

}


void display(struct Node *root){


    if(root==NULL){
        return;
    }

    display(root->left);
    printf("%d ",root->val);
    display(root->right);

}


int main(){

    struct Node *root = createNode(5);

    insert(3,root);
    insert(6,root);
    insert(8,root);
    insert(7,root);
    insert(2,root);

    display(root);    

    return 0;
}