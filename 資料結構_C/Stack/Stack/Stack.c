#include<stdio.h>
#include<stdlib.h>

#define STACKSiZE 100

struct stack{

    int array[STACKSiZE];
    int top;
};

int IsEmpty(struct stack* ps){

    if(ps->top == -1){return 1;}

    else{return 0;}
    }

int IsFull(struct stack* ps){

    if(ps -> top == STACKSiZE-1){return 1;}
    else{return 0;}

}

void push(struct stack* ps, int number){
    if(IsFull(ps) == 0 ){
        int index = ++(ps -> top);
        ps -> array[index] = number;
        }
    else{
        printf("The stack is full!\n");
    }

}

int pop(struct stack* ps){

    if(IsEmpty(ps) == 0){

       return ps -> array[(ps -> top)--];

    }
    else{
        printf("The stack is empty!\n");
        exit(1);//Á×§K¦^¶Ç­È
    }

}

int main(){

    struct stack st;
    st.top = -1;
    push(&st,5);
    push(&st,6);
    while(IsEmpty(&st) == 0){
        printf("%d ",pop(&st));
    }
    printf("\n%d", pop(&st));

    return 0;
}


