#include <stdio.h>
#include <stdlib.h>

#define max_size 5

struct Queue{
    int front;
    int rear;
    struct Guest{
        char name;
        int num;
    }g[max_size];
};

void get_top(struct Queue *queue){//取得在queue中最前面客人的代號
    if(!(queue->front == queue->rear + 1))
        printf("%c\n",queue->g[queue->front].name);
}

int sum(struct Queue *queue){//加總在queue中的客人
    int sum = 0,i;
    for(i = queue->front; i <= queue->rear; i++){
        sum += queue->g[i].num;
    }
    return sum;
}

void addQ(struct Queue *queue, char name, int num){
    if(!(queue->rear == max_size - 1)){
        queue->rear += 1;
        queue->g[queue->rear].name = name;
        queue->g[queue->rear].num = num;
    }
}

void deleteQ(struct Queue *queue){
    int i;
    if(!(queue->front == queue->rear + 1)){
        queue->front += 1;
        for(i = 0; i < queue->rear; i++){//將整個queue往下移1格，避免front、rear無限往上加
            queue->g[i].name = queue->g[i+1].name;
            queue->g[i] .num= queue->g[i+1].num;
        }
        queue->rear-=1;
        queue->front-=1;
    }
}

int redun(struct Queue *queue, char c){//檢查在queue中是否有重複代號的客人
    int i;
    for(i = queue->front; i <= queue->rear; i++){
        if(queue->g[i].name == c)
            return 1;
    }
    return 0;
}

int main()
{
    struct Queue q;
    q.front = 0;
    q.rear = -1;
    int input;
    scanf("%d", &input);
    while(input != -1){
        char c,x;
        int n;
        switch (input){
            case 1://input
                scanf(" %c %d",&c,&n);//運用scanf()的" %c"格式字串控制scanf讀取symbol時需要跳過所有的空白
                if(n > 0 && !redun(&q,c))
                    addQ(&q,c,n);
                break;
            case 2://count
                printf("%d\n",sum(&q));
                break;
            case 3://print queue 1st element
                get_top(&q);
                break;
            case 4://delete
                deleteQ(&q);
                break;
            default://delete
                printf("error\n");
                break;
        }
        scanf("%d", &input);
    }
    return 0;
}
