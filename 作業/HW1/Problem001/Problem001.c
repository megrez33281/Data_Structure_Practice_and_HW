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

    /*----讀取Postfix----*/
    char postfix[1000];//存放postfix
    scanf("%s",postfix);

    /*----Postfix計算----*/
    struct Stack stack;//在此count專為存放數字，不需存放運算子
    stack.top = -1;
    int i = 0;
    while(postfix[i] != '\0'){
        //數字丟入count中
        if(postfix[i] >= '0' && postfix[i] <= '9'){
            //數字由char轉int
            int tempNum = postfix[i];
            tempNum -= 48;
            float tempFloat = tempNum;
            push(&stack,tempFloat);
        }
        //若為運算元則從count中取出兩個數字進行計算，結果丟回count
        else{
            float b = pop(&stack);
            float a = pop(&stack);
            float answer = calculator(a,b,postfix[i]);
            push(&stack,answer);

        }
        i++;
    }

    printf("%.2f",pop(&stack));

   return 0;

}


