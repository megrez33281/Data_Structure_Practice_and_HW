#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE  40

struct stack  { /* a stack of integers */
    int top; /* indicate the position of the current stack top within the array */
    double num[MAXSIZE];
};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void push(struct stack *ps,double x){
	ps->num[++(ps->top)] = x;
}

double pop(struct stack *ps){
	return (ps->num[ps->top--]);
}

int main() {
	struct stack s;
	char input[MAXSIZE];
	double num1,num2;
	double result;
	char token;
	int i; 
    s.top = -1;
    scanf("%s",&input);
    for(i = 0; i < MAXSIZE; i++){
        token = input[i];
        if(token == '\0'){
            break;
        }
        switch(token){
            case '+':
                num2 = pop(&s);
                num1 = pop(&s);
                push(&s,num1+num2);
                break;
            case '-':
                num2 = pop(&s);
                num1 = pop(&s);
                push(&s,num1-num2);
                break;
            case '*':
                num2 = pop(&s);
                num1 = pop(&s);
                push(&s,num1*num2);
                break;
            case '/':
                num2 = pop(&s);
                num1 = pop(&s);
                push(&s,num1/num2);
                break;
            default:
                push(&s,token-'0');
                break;
        }
    }
    result = pop(&s);
    printf("%.2f",result);
	return 0;
}
