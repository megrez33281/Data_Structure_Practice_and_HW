#include<stdio.h>
#include<stdlib.h>

struct BinaryTree{

    int data;
    struct BinaryTree *left,*right;

};

struct BinaryTree* Create(){

    struct BinaryTree* bt = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    bt->data = -1;
    bt->left = NULL;
    bt->right = NULL;
    return bt;
}

int IsEmpty(struct BinaryTree* bt){


    return (bt->data == -1 && bt->left == NULL && bt -> right == NULL);

}

struct BinaryTree* MakeBT(struct BinaryTree* btl, int data, struct BinaryTree* btr){

    struct BinaryTree* bt = Create();
    bt->data = data;
    bt->left = btl;
    bt->right = btr;
    return bt;

}

struct BinaryTree* LChild(struct BinaryTree* bt){

    if(IsEmpty(bt)){
        printf("error\n");
        return -1;
    }
    return bt->left;
}

struct BinaryTree* RChild(struct BinaryTree* bt){

    if(IsEmpty(bt)){
        printf("error\n");
        return -1;
    }

    return bt->right;
}

int Data(struct BinaryTree* bt){

    if(IsEmpty(bt)){
        printf("error\n");
        return -1;
    }

    return bt->data;
}


int main(){
    struct BinaryTree* btl = MakeBT(Create(),10,Create());
    struct BinaryTree* btr = MakeBT(Create(),12,Create());
    struct BinaryTree* bt =  MakeBT(btl,8,btr);
    printf("%d\n",Data(bt));
    printf("%d\n",Data(LChild(bt)));
    printf("%d\n",Data(RChild(bt)));



    return 0;
}
