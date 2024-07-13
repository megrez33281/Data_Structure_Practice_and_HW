#include<stdio.h>
#include<stdlib.h>


struct Node{

    int info;
    struct Node* next;

};

struct Stack{

    struct Node* top;
};
struct Node null;

struct Stack CreateStack(){

    struct Stack stack;
    stack.top = &null;
    return stack;

};

int IsEmpty(struct Stack* stack){


    return (stack->top == &null);
}

void push(struct Stack* stack, int n){

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->info = n;
    node->next = stack->top;
    stack->top = node;

}

int pop(struct Stack* stack){

    if(IsEmpty(stack) == 1){
        printf("The stack is empty!\n");
        return -1;
    }

    int k = stack->top->info;
    struct Node* ptr = stack->top;
    stack-> top = stack->top->next;
    free(ptr);
    return k;
}


void PrintStack(struct Stack* stack){

    printf("Stack:");
    struct Node* ptr = stack->top;

    while(ptr != &null){
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");

}


int main(){
    struct Stack stack = CreateStack();

    push(&stack,1);
    push(&stack,2);
    printf("pop:%d\n",pop(&stack));
    printf("pop:%d\n",pop(&stack));
    printf("pop:%d\n",pop(&stack));
    PrintStack(&stack);


    return 0;
}

