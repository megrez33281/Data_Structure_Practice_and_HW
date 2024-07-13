#include<stdio.h>
#include<stdlib.h>
#define QUEUESIZE 6

struct Customer{
    //�ȤH
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

    return ((queue->tail+1)%QUEUESIZE == (queue->head%QUEUESIZE))?1:0; //tail���U�Ӧ�m��haed�A��ܤw�g�����۳s�A���F

}

void add(struct Queue* queue, struct Customer customer){
    if(IsFull(queue) == 0){
        queue->QueueArray[queue->tail] = customer;
        queue->tail = (queue->tail+1)%QUEUESIZE;//�T�O 0 <= tail <= QUEUESIZE
    }
    else{
        //printf("The Queue is full!\n");
    }

}

struct Customer delete(struct Queue* queue){

    if(IsEmpty(queue) == 0){
        struct Customer customer;
        customer = queue->QueueArray[queue->head];
        queue->head = (queue->head+1)%QUEUESIZE;  //�T�O 0 <= head <= QUEUESIZE

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
    CreateQueue(&queue);//�Ы�queue



    int input = 0;
    while(input != -1){
        scanf("%d",&input);

        if(input == 1){
            char CustomerName;
            int num;
            scanf(" %c %d",&CustomerName,&num); //Ū�����r���ɡA�ݪ`�N��i��N���e��J��enter�����@���r��Ū���A���ɥi�ǥѦb%����[�ťիة����Ҧ��Ů� (TAB�B space�B �� Enter)
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
            int index = queue.head; //�Hhead���_�I�Vtail�a��
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
            delete(&queue);//�N�ȤH�Ԩ�
         }

         else{
            if(input != -1){
                printf("error\n");}
         }




    }

    return 0;
}

