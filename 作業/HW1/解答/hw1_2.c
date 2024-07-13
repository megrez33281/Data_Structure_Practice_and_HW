#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1001

typedef struct Stack Stack;
struct Stack
{
	int top;
	char data[MAX_SIZE];
};

int isEmpty(struct Stack *stack)
{
	return stack->top == 0;
}

char peek(struct Stack *stack)
{
	return stack->data[stack->top];
}

char pop(struct Stack *stack)
{
	if(isEmpty(stack))
		return -1;
	else{
		return stack->data[stack->top--];
    }
}

void push(struct Stack *stack, char data)
{
   if(stack->top < MAX_SIZE)
   {
		stack->data[++stack->top] = data;
		return;
   }

}

int isOperator(char op)
{
	if(op == '+' || op == '-' || op == '*' || op == '/')
		return 1;
	else
    	return 0;
}

int priority(char op)
{
   switch(op)
   {
      case '+':
      case '-':
      	return 1;
      case '*':
      case '/':
      	return 2;
   }
   return -1;
}

// function definition of the revstr()
void revstr(char *str1)
{
    // declare variable
    int i, len, temp;
    len = strlen(str1); // use strlen() to get the length of str string

    // use for loop to iterate the string
    for (i = 0; i < len/2; i++)
    {
        // temp variable use to temporary hold the string
        temp = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = temp;
    }
}

void toPostfix(char infixExp[], char postfixExp[])
{
   Stack s = {.top = 0};
	int i = 0, j = 0;
	char item = infixExp[i], x;
	while(item != '\0')
	{
		if(isOperator(item) == 1)        /* means symbol is operator */
		{
			if(s.top == 0){
            	push(&s, item);
			}
			else{
                if(priority(item) < priority(peek(&s))){
                    while(!isEmpty(&s) && (priority(item) < priority(peek(&s)))){
                        postfixExp[j] = pop(&s);
                        j++;
                    }
                    push(&s, item);
                }
                else{
                    push(&s, item);
                }
			}
		}
		else
		{
			postfixExp[j] = item;              /* add operand symbol to postfix expr */
			j++;

		}
		i++;
		item = infixExp[i];  //go on next
	}

	while(s.top>0)
	{
		postfixExp[j] = pop(&s);
		j++;
	}
	postfixExp[j] = '\0';
	return;
}

int main()
{
  char c_str[MAX_SIZE] = {NULL}, postfix[MAX_SIZE] = {NULL};
  scanf("%s", c_str);
  //while(c_str != NULL){
  size_t len = strlen(c_str);

  revstr(c_str);
  toPostfix(c_str, postfix);
  revstr(postfix);


  for(int i = 0 ;i < strlen(postfix); i++){
    printf("%c", postfix[i]);
  }

      //scanf("%s", c_str);

  //}
  return 0;
}
