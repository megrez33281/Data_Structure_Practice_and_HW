#include<stdio.h>
#include<stdlib.h>
#define QUEUESIZE 6

struct Customer{
    //客人
    char name;
    int number;

};


struct Queue{

    struct Customer QueueArray[QUEUESIZE];
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

void add(struct Queue* queue, struct Customer customer){
    if(IsFull(queue) == 0){
        queue->QueueArray[queue->tail] = customer;
        queue->tail = (queue->tail+1)%QUEUESIZE;//確保 0 <= tail <= QUEUESIZE
    }
    else{
        //printf("The Queue is full!\n");
    }

}

struct Customer delete(struct Queue* queue){

    if(IsEmpty(queue) == 0){
        struct Customer customer;
        customer = queue->QueueArray[queue->head];
        queue->head = (queue->head+1)%QUEUESIZE;  //確保 0 <= head <= QUEUESIZE

        return customer;
    }

    else{
        //printf("The Queue is Empty!\n");
    }}

void PrintQueue(struct Queue* queue){

    int from = queue->head;

    while(from != queue->tail){

        printf("%c %d ",queue->QueueArray[from].name, queue->QueueArray[from].number);
        from = (from + 1 )%QUEUESIZE;
    }
    printf("\n");

}




int main(){

    struct Queue queue;
    CreateQueue(&queue);//創建queue



    int input = 0;
    while(input != -1){
        scanf("%d",&input);

        if(input == 1){
            char CustomerName;
            int num;
            scanf(" %c %d",&CustomerName,&num); //讀取為字元時，需注意其可能將先前輸入之enter直接作為字元讀取，此時可藉由在%左邊加空白建忽略所有空格 (TAB、 space、 及 Enter)
            int repeat = 0;
            int index = queue.head;
            while(index != queue.tail){
                if(queue.QueueArray[index].name == CustomerName){repeat = 1;}
                index++;
                index %= QUEUESIZE;}
            if(repeat == 0){
                struct Customer newCustomer;
                newCustomer.name = CustomerName;
                newCustomer.number = num;
                add(&queue,newCustomer);}
            }



         else if(input == 2){
            int index = queue.head; //以head為起點向tail靠近
            int total = 0;
            while(index != queue.tail){
                total += queue.QueueArray[index].number;
                index++;
                index %= QUEUESIZE;}
            printf("%d\n",total);
         }

         else if(input == 3){
            printf("%c\n", queue.QueueArray[queue.head].name);//
         }

         else if(input == 4){
            delete(&queue);//將客人拉走
         }

         else{
            if(input != -1){
                printf("error\n");}
         }




    }

    return 0;
}

