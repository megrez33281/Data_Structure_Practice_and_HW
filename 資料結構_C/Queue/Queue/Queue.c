#include<stdio.h>
#include<stdlib.h>
#define QUEUESIZE 5

struct Queue{

    int queue[QUEUESIZE];
    int head;
    int tail;
};

void CreateQ(struct Queue *AQueue){

    AQueue -> head = 0;
    AQueue -> tail = 0;//tail指向的空間不計入Queue中
};


int isFull(struct Queue *AQueue){
    //檢查queue是否滿了

    return ((AQueue->tail + 1) %QUEUESIZE == (AQueue->head) %QUEUESIZE )?1:0; //在此以環狀形成queue，犧牲一格空間來檢查是否已滿

}

int isEmpyt(struct Queue *AQueue){


    return (AQueue->tail == AQueue-> head) ? 1:0;
}

void add(struct Queue *AQueue, int number){

    if(isFull(AQueue) == 0){
        AQueue -> queue[AQueue -> tail] = number;
        //printf("%d\n",AQueue -> queue[AQueue -> tail] );
        AQueue->tail++;
        AQueue->tail %= QUEUESIZE;
    }


    else{
        printf("The Queue is full!\n");
    }


}

int delete(struct Queue *AQueue){

    int num;
    if(isEmpyt(AQueue) == 0){

        num = AQueue -> queue[(AQueue->head)];
        AQueue->head++;
        AQueue->head %= QUEUESIZE;
        return num;
    }

    else{

        printf("The Queue is empty!\n");

    }


}

void PrintQueue(struct Queue* AQueue){

    int index = AQueue -> head;

    printf("Queue：");
    while((index%QUEUESIZE) != ((AQueue -> tail) % QUEUESIZE)){
        //printf("index = %d ",index);
        printf("%d ",AQueue->queue[index]);
        index++;
        index %= QUEUESIZE;

    }
    printf("\n");


}



int main(){

    struct Queue queue;
    CreateQ(&queue);

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


