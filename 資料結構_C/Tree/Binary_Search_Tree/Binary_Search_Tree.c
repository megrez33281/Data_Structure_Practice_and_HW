#include<stdio.h>
#include<stdlib.h>

struct tree{
    int data;
    struct tree* LeftChild;
    struct tree* RightChild;

};

struct tree* Create(){
    //return a empty tree
    struct tree* Atree = (struct tree*)malloc(sizeof(struct tree));
    Atree->data = -1;
    Atree->LeftChild = NULL;
    Atree->RightChild = NULL;
    return Atree;

}

int IsEmpty(struct tree* Anode){
    //可檢測是否為leaf
    return (Anode->LeftChild == NULL && Anode->RightChild == NULL);
}

struct tree* MakeBT(struct tree* LeftChild, int data ,struct tree* RightChild){
    //建立一個含指定左子樹、右子樹、值的tree
    struct tree* Atree = Create();
    Atree->data = data;
    Atree->LeftChild = LeftChild;
    Atree->RightChild = RightChild;
    return Atree;

}

void MakeLBT(struct tree* root, struct tree* LeftChild){
    //生成左子樹
    if(root == NULL){
        printf("The tree is empty!\n");
    }
    else{
        root->LeftChild = LeftChild;
    }

}

void MakeRBT(struct tree* root, struct tree* RightChild){
    //生成右子樹
    if(root == NULL){
        printf("The tree is empty!\n");
    }
    else{
        root->RightChild = RightChild;
    }

}

void SetData(struct tree* root, int data){
    //改變data
    if(root == NULL){
        printf("The tree is empty!\n");
    }
    else{
        root->data = data;
    }

}

struct tree* Lchild(struct tree* Atree){
    //取得左子樹
    if(Atree == NULL){
        printf("The tree is empty!\n");
        return -1;
    }

    return Atree->LeftChild;
}

struct tree* Rchild(struct tree* Atree){
    //取得右子樹
    if(Atree == NULL){
        printf("The tree is empty!\n");
        return -1;
    }

    return Atree->RightChild;
}

int Data(struct tree* Atree){
    //取得data
    if(Atree == NULL){
        printf("The tree is empty!\n");
        return -1;
    }

    return Atree->data;
}


void InOrder(struct tree* root){
    //中序遍歷
    if(root != NULL){//出口
        //左 右 中
        InOrder(Lchild(root));
        printf("%d ",Data(root));
        InOrder(Rchild(root));}

}

void PreOrder(struct tree* root){
    //前序遍歷
    if(root != NULL){//出口
        //中 左 右
        printf("%d ",Data(root));
        PreOrder(Lchild(root));
        PreOrder(Rchild(root));}

}

void PostOrder(struct tree* root){
    //後序遍歷
    if(root != NULL){//出口
        //左 右 中
        PostOrder(Lchild(root));
        PostOrder(Rchild(root));
        printf("%d ",Data(root));}

}



int main(){

    int n = 0;  //數字數量
    while(n != -1){
        scanf("%d",&n);
        if(n == -1){break;}

        int nums[n];
        for(int i=0; i<n; i++){
            scanf("%d",&nums[i]);}   //將數字儲存

        //將數字生成 Binary Search Tree
        struct tree* root = NULL;
        for(int i=0; i<n; i++){
            //生成一個data為對應數字的tree
            struct tree* subTree = MakeBT(NULL,nums[i],NULL);
            //做為根
            if(root == NULL){
                root = subTree;
            }
            //接到tree上
            else{
                struct tree* temp = root;   //生成一個指標用來找到新的數字要接的位置
                while(!IsEmpty(temp)){
                    //大於等於根之data往右邊
                    if(nums[i] >= Data(temp)){
                        if(temp->RightChild == NULL){break;}//避免右側為空
                        temp = Rchild(temp);
                    }
                    //小於根之data往左邊
                    else{
                        if(temp->LeftChild == NULL){break;}//避免左側為空
                        temp = Lchild(temp);
                    }}
                //while結束後，temp應指向subTree要放的地方之根
                //大於等於根，將subTree放根之右邊
                if(nums[i] >= Data(temp)){
                    MakeRBT(temp,subTree);
                }
                //小於根，將subTree放根之左邊
                else{
                    MakeLBT(temp,subTree);
                }

            }
        }
        //輸出
        printf("Preorder: ");
        PreOrder(root);//前序
        printf("\n");
        printf("Inorder: ");
        InOrder(root);//中序
        printf("\n");
        printf("Postorder: ");
        PostOrder(root);//後序
        printf("\n");

        fflush(stdin);  //清空緩衝區
    }
    return 0;
}
