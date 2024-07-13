#include<stdio.h>
#include<stdlib.h>


struct node{

    int info;
    struct node* next;

};

struct Stack{
    struct node* pointer;
    int count;
};

void CreateStack(struct Stack* stack){

    struct node *buttom = (struct node*)malloc(sizeof(struct node));
    stack -> pointer = &buttom;
    stack -> count = 0;
}

void Push(struct Stack* stack, int number){

    struct node *element = (struct node*)malloc(sizeof(struct node));
    element->info = number;
    element->next = stack->pointer;
    stack->pointer = element;
    stack -> count++;


};

int Pop(struct Stack* stack){

    int k;
    if(stack->pointer->next != NULL){

        struct node* temp = stack -> pointer;
        k = stack->pointer->info;
        stack ->pointer = stack->pointer->next;
        free(temp);
        stack -> count--;
        return k;
    }

    else{
        printf("The stack is empty!\n");

    }


}

void PrintStack(struct Stack* stack){

    struct node* list;
    list = stack->pointer;
    int total = stack->count;
    printf("Stack:");
    while(total > 0){
        printf("%d ",list->info);
        list = list->next;
        total--;
    }
    printf("\n");
}

int main(){

    struct Stack stack;
    CreateStack(&stack);
    Push(&stack,1);
    Push(&stack,2);
    Push(&stack,3);
    Push(&stack,4);
    Push(&stack,5);
    printf("%d\n",Pop(&stack));
    struct node* temp;
    temp = stack.pointer;
    printf("%d\n",temp->info);
    PrintStack(&stack);





    return 0;
}

