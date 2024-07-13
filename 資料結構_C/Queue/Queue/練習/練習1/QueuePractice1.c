#include<stdio.h>
#include<stdlib.h>
#define QUEUESIZE 5

struct Queue{

    int QueueArray[QUEUESIZE];
    int head;
    int tail;

};

void CreateQueue(struct Queue* queue){

    queue-> head = 0;
    queue-> tail = 0;
}

int IsEmpty(struct Queue* queue){

    return (queue->tail == queue->head)?1:0;
}

int IsFull(struct Queue* queue){

    return ((queue->tail+1)%QUEUESIZE == (queue->head%QUEUESIZE))?1:0; //tail的下個位置為haed，表示已經首尾相連，滿了

}

void add(struct Queue* queue, int Number){
    if(IsFull(queue) == 0){
        queue->QueueArray[queue->tail] = Number;
        queue->tail = (queue->tail+1)%QUEUESIZE;
    }
    else{
        printf("The Queue is full!\n");
    }

}

int delete(struct Queue* queue){

    if(IsEmpty(queue) == 0){
        int k;
        k = queue->QueueArray[queue->head];
        queue->head = (queue->head+1)%QUEUESIZE;

        return k;
    }

    else{
        printf("The Queue is Empty!\n");
    }}

void PrintQueue(struct Queue* queue){

    int from = queue->head;

    while(from != queue->tail){

        printf("%d ",queue->QueueArray[from]);
        from = (from + 1 )%QUEUESIZE;
    }
    printf("\n");

}

int main(){

    struct Queue queue;
    CreateQueue(&queue);


    add(&queue,1);//0
    add(&queue,2);//1
    add(&queue,3);//2
    add(&queue,4);//3
    add(&queue,5);
    printf("head = %d tail = %d\n", queue.head,queue.tail);

    PrintQueue(&queue);
    printf("head = %d tail = %d\n", queue.head,queue.tail);
    printf("%d\n",delete(&queue));
    PrintQueue(&queue);
    add(&queue,6);
    printf("head = %d tail = %d\n", queue.head,queue.tail);
    PrintQueue(&queue);
    add(&queue,7);
    printf("%d\n",delete(&queue));
    add(&queue,7);
    PrintQueue(&queue);
    printf("%d\n",delete(&queue));
    printf("%d\n",delete(&queue));
    printf("head = %d tail = %d\n", queue.head,queue.tail);
    printf("%d\n",delete(&queue));
    printf("%d\n",delete(&queue));
    printf("head = %d tail = %d\n", queue.head,queue.tail);
    add(&queue,8);
    add(&queue,9);
    add(&queue,10);
    add(&queue,11);
    add(&queue,12);
    PrintQueue(&queue);
    return 0;
}

