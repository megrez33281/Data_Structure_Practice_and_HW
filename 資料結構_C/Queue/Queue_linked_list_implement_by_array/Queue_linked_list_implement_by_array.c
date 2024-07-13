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

struct Queue{
    int front,rear;
};

struct Queue CreateQueue(){

    struct Queue queue;
    queue.front = -1;   //當front=-1，queue為空
    queue.rear = -1;
    return queue;
};

void add(struct Queue* queue, int n){
    //從rear端添加
    //確認可以從倉庫申請node
    int nodeIndex = getNode();
    if(nodeIndex != -1){
        nodeList[nodeIndex].info = n;
        //若queue不為空(為空直接添加)
        if(queue->front != -1){
           nodeList[queue->rear].next = nodeIndex;  //將新的node接到rear後面
        }

        //若queue為空，在新node添加後，也將front指向新node
        else{
            queue -> front = nodeIndex;
        }

        queue->rear = nodeIndex;      //rear指向新添加的node
    }

    else{
        printf("overflow!\n");
    }

}

int delafter(struct Queue* queue){

    //從front端輸出
    //判斷queue不為空
    if(queue->front != -1){
        int k = nodeList[queue->front].info;
        int freeIndex = queue->front;
        queue -> front = nodeList[queue->front].next;
        freeNode(freeIndex);

        return k;
    }

    else{
        printf("The queue is empty!\n");
        return -1;
    }

}

void PrintQueue(struct Queue* queue){

    int index = queue->front;
    printf("Queue:");
    while(index != -1){
        printf("%d ", nodeList[index].info);
        index = nodeList[index].next;
    }
    printf("\n");
}

int main(){
    CreateAvail();  //創建倉庫

    struct Queue queue = CreateQueue();
    printf("Line 115 head = %d tail = %d\n", queue.front,queue.rear);
    add(&queue,1);//0
    add(&queue,2);//1
    add(&queue,3);//2
    add(&queue,4);//3
    add(&queue,5);
    printf("Line 121 head = %d tail = %d\n", queue.front,queue.rear);

    PrintQueue(&queue);
    printf("Line 124 head = %d tail = %d\n", queue.front,queue.rear);
    printf("Line 125 %d\n",delafter(&queue));
    PrintQueue(&queue);
    add(&queue,6);
    printf("Line 128 head = %d tail = %d\n", queue.front,queue.rear);
    PrintQueue(&queue);
    add(&queue,7);
    printf("Line 131 %d\n",delafter(&queue));
    add(&queue,7);
    PrintQueue(&queue);
    printf("Line 134 %d\n",delafter(&queue));
    printf("Line 135 %d\n",delafter(&queue));
    printf("Line 136 head = %d tail = %d\n", queue.front,queue.rear);
    printf("Line 137 %d\n",delafter(&queue));
    printf("Line 138 %d\n",delafter(&queue));
    printf("Line 139 head = %d tail = %d\n", queue.front,queue.rear);
    add(&queue,8);
    add(&queue,9);
    add(&queue,10);
    add(&queue,11);
    add(&queue,12);
    PrintQueue(&queue);



    return 0;
}

