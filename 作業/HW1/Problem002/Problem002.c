#include<stdio.h>
#include<stdlib.h>

#define STACKSiZE 1000//設定stack的最大容量


struct Stack{
    char array[STACKSiZE];
    int top;
};

int IsEmpty(struct Stack* ps){
/*check if the stack is empty*/
    if(ps->top == -1){return 1;}

    else{return 0;}
    }

int IsFull(struct Stack* ps){
/*check if the stack is full*/
    if(ps -> top == STACKSiZE-1){return 1;}
    else{return 0;}

}

void push(struct Stack* ps, char charatcer){
/*push an element into the top of stack*/
    if(IsFull(ps) == 0 ){
        int index = ++(ps -> top);
        ps -> array[index] = charatcer;
        }
    else{
        printf("The stack is full!\n");
    }

}



char pop(struct Stack* ps){
/*get the top element from the stack*/
    if(IsEmpty(ps) == 0){

       return ps -> array[(ps -> top)--];//return array[ps -> top],top--

    }
    else{
        printf("The stack is empty!\n");
        exit(1);//避免回傳值
    }

}

int isp(char operation){
    //get the in stack precedence
    int ISP;
    switch(operation){
        case '+' : ISP = 12;
        break;

        case '-' : ISP = 12;
        break;

        case '*' : ISP = 13;
        break;

        case '/' : ISP = 13;
        break;

        case '%' : 13;
        break;

        deafult : ISP = -1;
        break;
    }

    return ISP;
}


int icp(char operation){
//get the in comment precedence
    int ICP;
    switch(operation){

        case '+' : ICP = 12;
        break;

        case '-' : ICP = 12;
        break;

        case '*' : ICP = 13;
        break;

        case '/' : ICP = 13;
        break;

        case '%' : 13;
        break;

        deafult : ICP = -1;
        break;
    }

    return ICP;
    }

int main(){
    /*將Infix轉成Prefix，過程類似Infix轉成Postfix，只是改成由右到左掃描*/
    /*由於由右到左掃描，輸出時需要再顛倒*/
    /*注意：Infix轉成Prefix時，只需當前運算子之icp小於stack頂部之isp即可pop(&stack)，Infix轉Postfix時，需要當前運算子之icp小於等於stack頂部之isp*/
    char formula[1000];
    char output[1000];
    scanf("%s",formula);

    int OutputIndex = 0;

    //存放運算子
    struct Stack stack;
    stack.top = -1;

    struct Stack store;
    store.top = -1;

    int length = 0;
    while(formula[length] != '\0'){length++;}
    length--;

    while(length >= 0){
        char temp = formula[length];

        //讀取為運算元
        if('0' <= temp && temp <= '9'){
           push(&store,temp);
           }

        //讀取為運算子
        else{
            //將stack中isp大於等於當前運算子之icp者皆放入store
            while(IsEmpty(&stack) == 0){
                char stackTop = pop(&stack);
                if(icp(temp) < isp(stackTop)){
                    push(&store,stackTop);
                }
                else{
                    push(&stack,stackTop);//將取出之運算子放回
                    break;}}

            push(&stack,temp);}//放入新運算子

        length--;}

    //將stack內剩餘所有運算子放入store
    while(IsEmpty(&stack) == 0){
        push(&store,pop(&stack));}

    while(IsEmpty(&store) == 0){
        printf("%c",pop(&store));
        }

   return 0;

}


