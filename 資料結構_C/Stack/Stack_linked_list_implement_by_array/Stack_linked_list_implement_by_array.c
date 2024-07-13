#include<stdio.h>
#include<stdlib.h>
#define AVAILSIZE 500

/*�Harray��@Linked List*/
//�Hnode�bnodeList��������index�@������
struct Node{
    int info, next;
};
struct Node nodeList[AVAILSIZE]; //�إߤ@�Ӥj�p��AVAILSIZE��node�}�C
int avail = 0;//�Ū�node���ܮw�Aavail���ܮw�Y����node��index


void CreateAvail(){
    //�ܮw��l��
    for(int i=0; i<AVAILSIZE; i++){
        nodeList[i].next= i+1;
        if(i == AVAILSIZE-1){nodeList[i].next = -1;}
        }
}

int getNode(){
    //�qavail�����X�@��node
    if(avail == -1){
        printf("overflow\n");
        return -1;
    }

    int NodeIndex = avail;         //�Nnode���V�ܮw�Y����node
    avail = nodeList[avail].next;   //�O�ܮw���U�@��node�����ܮw�Y��
    nodeList[NodeIndex].next = -1;  //�����P�ܮw��node���pô


    return NodeIndex;

}

void freeNode(int NodeIndex){
    //�Nnode�٦^��avail�Y��
    nodeList[NodeIndex].next = avail;//node.next = �ܮw�Y��
    avail = NodeIndex;//avail��node�bnodeList��������index
}

struct Stack{

    int pointer;    //���Vpointer����
};

struct Stack CreateStack(){
    struct Stack stack;
    stack.pointer = -1;

    return  stack;
};

void push(struct Stack* stack, int n){
    int nodeIndex = getNode();
    if(nodeIndex != -1){//�P�w�Doverflow(�ӽФ���Ŷ�)
        if(stack -> pointer != -1){//stack������
            nodeList[nodeIndex].next = stack->pointer;  //�N�s��node(nodeList[nodeIndex])����stack�Y��
            }
        nodeList[nodeIndex].info = n;
        stack->pointer = nodeIndex;                 //��spointer

    }

    else{
        printf("overflow!\n");
    }

}

int pop(struct Stack* stack){

    if(stack->pointer != -1){
        int k = nodeList[stack->pointer].info;
        int freeIndex = stack->pointer;
        stack->pointer = nodeList[stack->pointer].next;      //pointer���U��
        freeNode(freeIndex);    //�Npointer���V��node�٦^�ܮw


        return k;
    }

    else{
        printf("The stack is empty!\n");
        return -1;
    }

}

int main(){
    CreateAvail();
    struct Stack temp = CreateStack();
    push(&temp,5);
    push(&temp,6);
    printf("%d\n",pop(&temp));
    printf("%d\n",pop(&temp));
    printf("%d\n",pop(&temp));
    printf("%d\n",getNode());
    printf("%d\n",getNode());


    return 0;
}

