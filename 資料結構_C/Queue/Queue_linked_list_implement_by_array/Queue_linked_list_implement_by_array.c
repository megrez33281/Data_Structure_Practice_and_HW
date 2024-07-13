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

struct Queue{
    int front,rear;
};

struct Queue CreateQueue(){

    struct Queue queue;
    queue.front = -1;   //��front=-1�Aqueue����
    queue.rear = -1;
    return queue;
};

void add(struct Queue* queue, int n){
    //�qrear�ݲK�[
    //�T�{�i�H�q�ܮw�ӽ�node
    int nodeIndex = getNode();
    if(nodeIndex != -1){
        nodeList[nodeIndex].info = n;
        //�Yqueue������(���Ū����K�[)
        if(queue->front != -1){
           nodeList[queue->rear].next = nodeIndex;  //�N�s��node����rear�᭱
        }

        //�Yqueue���šA�b�snode�K�[��A�]�Nfront���V�snode
        else{
            queue -> front = nodeIndex;
        }

        queue->rear = nodeIndex;      //rear���V�s�K�[��node
    }

    else{
        printf("overflow!\n");
    }

}

int delafter(struct Queue* queue){

    //�qfront�ݿ�X
    //�P�_queue������
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
    CreateAvail();  //�Ыحܮw

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

