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
    //�i�˴��O�_��leaf
    return (Anode->LeftChild == NULL && Anode->RightChild == NULL);
}

struct tree* MakeBT(struct tree* LeftChild, int data ,struct tree* RightChild){
    //�إߤ@�ӧt���w���l��B�k�l��B�Ȫ�tree
    struct tree* Atree = Create();
    Atree->data = data;
    Atree->LeftChild = LeftChild;
    Atree->RightChild = RightChild;
    return Atree;

}

void MakeLBT(struct tree* root, struct tree* LeftChild){
    //�ͦ����l��
    if(root == NULL){
        printf("The tree is empty!\n");
    }
    else{
        root->LeftChild = LeftChild;
    }

}

void MakeRBT(struct tree* root, struct tree* RightChild){
    //�ͦ��k�l��
    if(root == NULL){
        printf("The tree is empty!\n");
    }
    else{
        root->RightChild = RightChild;
    }

}

void SetData(struct tree* root, int data){
    //����data
    if(root == NULL){
        printf("The tree is empty!\n");
    }
    else{
        root->data = data;
    }

}

struct tree* Lchild(struct tree* Atree){
    //���o���l��
    if(Atree == NULL){
        printf("The tree is empty!\n");
        return -1;
    }

    return Atree->LeftChild;
}

struct tree* Rchild(struct tree* Atree){
    //���o�k�l��
    if(Atree == NULL){
        printf("The tree is empty!\n");
        return -1;
    }

    return Atree->RightChild;
}

int Data(struct tree* Atree){
    //���odata
    if(Atree == NULL){
        printf("The tree is empty!\n");
        return -1;
    }

    return Atree->data;
}


void InOrder(struct tree* root){
    //���ǹM��
    if(root != NULL){//�X�f
        //�� �k ��
        InOrder(Lchild(root));
        printf("%d ",Data(root));
        InOrder(Rchild(root));}

}

void PreOrder(struct tree* root){
    //�e�ǹM��
    if(root != NULL){//�X�f
        //�� �� �k
        printf("%d ",Data(root));
        PreOrder(Lchild(root));
        PreOrder(Rchild(root));}

}

void PostOrder(struct tree* root){
    //��ǹM��
    if(root != NULL){//�X�f
        //�� �k ��
        PostOrder(Lchild(root));
        PostOrder(Rchild(root));
        printf("%d ",Data(root));}

}



int main(){

    int n = 0;  //�Ʀr�ƶq
    while(n != -1){
        scanf("%d",&n);
        if(n == -1){break;}

        int nums[n];
        for(int i=0; i<n; i++){
            scanf("%d",&nums[i]);}   //�N�Ʀr�x�s

        //�N�Ʀr�ͦ� Binary Search Tree
        struct tree* root = NULL;
        for(int i=0; i<n; i++){
            //�ͦ��@��data�������Ʀr��tree
            struct tree* subTree = MakeBT(NULL,nums[i],NULL);
            //������
            if(root == NULL){
                root = subTree;
            }
            //����tree�W
            else{
                struct tree* temp = root;   //�ͦ��@�ӫ��ХΨӧ��s���Ʀr�n������m
                while(!IsEmpty(temp)){
                    //�j�󵥩�ڤ�data���k��
                    if(nums[i] >= Data(temp)){
                        if(temp->RightChild == NULL){break;}//�קK�k������
                        temp = Rchild(temp);
                    }
                    //�p��ڤ�data������
                    else{
                        if(temp->LeftChild == NULL){break;}//�קK��������
                        temp = Lchild(temp);
                    }}
                //while������Atemp�����VsubTree�n�񪺦a�褧��
                //�j�󵥩�ڡA�NsubTree��ڤ��k��
                if(nums[i] >= Data(temp)){
                    MakeRBT(temp,subTree);
                }
                //�p��ڡA�NsubTree��ڤ�����
                else{
                    MakeLBT(temp,subTree);
                }

            }
        }
        //��X
        printf("Preorder: ");
        PreOrder(root);//�e��
        printf("\n");
        printf("Inorder: ");
        InOrder(root);//����
        printf("\n");
        printf("Postorder: ");
        PostOrder(root);//���
        printf("\n");

        fflush(stdin);  //�M�Žw�İ�
    }
    return 0;
}
