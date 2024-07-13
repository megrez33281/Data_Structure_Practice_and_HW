#include<stdio.h>
#include<stdlib.h>
#define AVAILSIZE 500

/*以array實作Linked List*/
//以node在nodeList中對應的index作為指標
struct Node{
    int info, next;
};
struct Node nodeList[AVAILSIZE]; //建立一個大小為AVAILSIZE的node陣列
int avail = 0;//空的node的倉庫，avail為倉庫頭部之node之index


void CreateAvail(){
    //倉庫初始化
    for(int i=0; i<AVAILSIZE; i++){
        nodeList[i].next= i+1;
        if(i == AVAILSIZE-1){nodeList[i].next = -1;}
        }
}

int getNode(){
    //從avail中取出一個node
    if(avail == -1){
        printf("overflow\n");
        return -1;
    }

    int NodeIndex = avail;         //將node指向倉庫頭部的node
    avail = nodeList[avail].next;   //令倉庫中下一個node成為倉庫頭部
    nodeList[NodeIndex].next = -1;  //取消與倉庫中node之聯繫


    return NodeIndex;

}

void freeNode(int NodeIndex){
    //將node還回到avail頭部
    nodeList[NodeIndex].next = avail;//node.next = 倉庫頭部
    avail = NodeIndex;//avail為node在nodeList中對應的index
}

struct Stack{

    int pointer;    //指向pointer頂部
};

struct Stack CreateStack(){
    struct Stack stack;
    stack.pointer = -1;

    return  stack;
};

void push(struct Stack* stack, int n){
    int nodeIndex = getNode();
    if(nodeIndex != -1){//判定非overflow(申請不到空間)
        if(stack -> pointer != -1){//stack不為空
            nodeList[nodeIndex].next = stack->pointer;  //將新的node(nodeList[nodeIndex])接到stack頭部
            }
        nodeList[nodeIndex].info = n;
        stack->pointer = nodeIndex;                 //更新pointer

    }

    else{
        printf("overflow!\n");
    }

}

int pop(struct Stack* stack){

    if(stack->pointer != -1){
        int k = nodeList[stack->pointer].info;
        int freeIndex = stack->pointer;
        stack->pointer = nodeList[stack->pointer].next;      //pointer往下指
        freeNode(freeIndex);    //將pointer指向之node還回倉庫


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

