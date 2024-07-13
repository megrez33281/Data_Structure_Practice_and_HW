#include<stdio.h>
#include<stdlib.h>

#define STACKSiZE 1000//設定stack的最大容量


struct Stack{
    float array[STACKSiZE];
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

void push(struct Stack* ps, float charatcer){
/*push an element into the top of stack*/
    if(IsFull(ps) == 0 ){
        int index = ++(ps -> top);
        ps -> array[index] = charatcer;
        }
    else{
        printf("The stack is full!\n");
    }

}



float pop(struct Stack* ps){
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

float calculator(float a, float b, char operation){
    /*calculate the char type of operation*/
    float answer = 0;
    switch(operation){
        case '*': answer = a*b;
        break;

        case '/': answer = a/b;
        break;

        case '+': answer = a+b;
        break;

        case '-': answer = a-b;
        break;

        default: answer = 0;
        break;
    }
    return answer;
}

int main(){

    /*----Infix轉Postfix----*/
    char formula[1000];
    char postfix[1000];//存放postfix
    scanf("%s",formula);
    int PostfixIndex = 0;

    //存放運算子
    struct Stack stack;
    stack.top = -1;

    int i = 0;
    while(formula[i] != '\0'){
        char temp = formula[i];

        //讀取為運算元
        if('0' <= temp && temp <= '9'){
           postfix[PostfixIndex] = temp;
           PostfixIndex++;
           }

        //讀取為運算子
        else{
            //將stack中isp大於等於當前運算子之icp者皆放入store
            while(IsEmpty(&stack) == 0){
                float stackTop = pop(&stack);
                int tempNum = stackTop;
                char CharOfStackTop = tempNum;//將stack頂部之float轉成char(得到運算子)
                if(icp(temp) <= isp(CharOfStackTop)){
                    postfix[PostfixIndex] = CharOfStackTop;
                    PostfixIndex++;
                }
                else{
                    push(&stack,stackTop);//將取出之運算子放回
                    break;}}

            int acsii = temp;
            push(&stack,acsii);
            }//放入新運算子

        i++;}

    while(IsEmpty(&stack) == 0){
        int tempNum = pop(&stack);
        postfix[PostfixIndex] = tempNum;
        PostfixIndex++;
        }
    printf("%s",postfix);
}
