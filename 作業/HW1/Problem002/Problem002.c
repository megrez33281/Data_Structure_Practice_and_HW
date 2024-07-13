#include<stdio.h>
#include<stdlib.h>

#define STACKSiZE 1000//�]�wstack���̤j�e�q


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
        exit(1);//�קK�^�ǭ�
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
    /*�NInfix�নPrefix�A�L�{����Infix�নPostfix�A�u�O�令�ѥk�쥪���y*/
    /*�ѩ�ѥk�쥪���y�A��X�ɻݭn�A�A��*/
    /*�`�N�GInfix�নPrefix�ɡA�u�ݷ�e�B��l��icp�p��stack������isp�Y�ipop(&stack)�AInfix��Postfix�ɡA�ݭn��e�B��l��icp�p�󵥩�stack������isp*/
    char formula[1000];
    char output[1000];
    scanf("%s",formula);

    int OutputIndex = 0;

    //�s��B��l
    struct Stack stack;
    stack.top = -1;

    struct Stack store;
    store.top = -1;

    int length = 0;
    while(formula[length] != '\0'){length++;}
    length--;

    while(length >= 0){
        char temp = formula[length];

        //Ū�����B�⤸
        if('0' <= temp && temp <= '9'){
           push(&store,temp);
           }

        //Ū�����B��l
        else{
            //�Nstack��isp�j�󵥩��e�B��l��icp�̬ҩ�Jstore
            while(IsEmpty(&stack) == 0){
                char stackTop = pop(&stack);
                if(icp(temp) < isp(stackTop)){
                    push(&store,stackTop);
                }
                else{
                    push(&stack,stackTop);//�N���X���B��l��^
                    break;}}

            push(&stack,temp);}//��J�s�B��l

        length--;}

    //�Nstack���Ѿl�Ҧ��B��l��Jstore
    while(IsEmpty(&stack) == 0){
        push(&store,pop(&stack));}

    while(IsEmpty(&store) == 0){
        printf("%c",pop(&store));
        }

   return 0;

}


