#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node* next;

};

struct Queue{

    struct Node* front; //指向頭部的指標
    struct Node* rear;  //指向尾部的指標

};

struct Queue CreateQueue(){

    struct Queue queue;
    struct Node* null = (struct Node*)malloc(sizeof(struct Node));
    queue.front = null;
    queue.rear = null;

    return queue;
};

void add(struct Queue* queue, int n){


    struct Node* node = (struct Node*)malloc(sizeof(struct Node));;
    node->info = n;

    queue->rear->next = node;  //將rear指向的node連接到新的node
    queue->rear = node;        //將rear指向新的node

}

int delafter(struct Queue* queue){

    if(queue->front == queue->rear){
        printf("The queue is empty!\n");
        return;
    }

    int k;
    struct Node* ptr = queue->front;
    queue->front = queue->front->next;
    k = queue->front->info;
    free(ptr);
    return k;

}

void PrintQueue(struct Queue* queue){

    printf("Queue:");
    struct Node* ptr = queue->front;
    while(ptr != queue->rear){
        ptr = ptr->next;
        printf("%d ",ptr->info);

    }

    printf("\n");

}




int main(){


    struct Queue queue = CreateQueue();
    add(&queue,1);//0
    add(&queue,2);//1
    add(&queue,3);//2
    add(&queue,4);//3
    add(&queue,5);

    PrintQueue(&queue);

    printf("Line 125 %d\n",delafter(&queue));
    PrintQueue(&queue);
    add(&queue,6);

    PrintQueue(&queue);
    add(&queue,7);
    printf("Line 131 %d\n",delafter(&queue));
    add(&queue,7);
    PrintQueue(&queue);
    printf("Line 134 %d\n",delafter(&queue));
    printf("Line 135 %d\n",delafter(&queue));

    printf("Line 137 %d\n",delafter(&queue));
    printf("Line 138 %d\n",delafter(&queue));

    add(&queue,8);
    add(&queue,9);
    add(&queue,10);
    add(&queue,11);
    add(&queue,12);
    PrintQueue(&queue);



    return 0;
}

