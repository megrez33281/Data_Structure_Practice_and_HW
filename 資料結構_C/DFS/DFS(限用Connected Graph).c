#include <windows.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node* next;

};

struct Stack{

    struct Node* top;

};

struct Stack CreateStack(){

    struct Stack stack;
    stack.top = NULL;

    return stack;

}

int IsEmpty(struct Stack* stack){

    return stack->top == NULL;
}

void Push(struct Stack* stack, int data){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;

    //stack����
    if(stack->top == NULL){
        stack->top = node;
        stack->top->next = NULL; //�]�m����
    }

    else{
        node->next = stack->top;
        stack->top = node;
    }

}

int Pop(struct Stack* stack){

    if(stack->top == NULL){
        return -1;
    }

    else{
        int k = stack->top->data;
        struct Stack* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);

        return k;

    }


}

void PrintStack(struct Stack* stack){

    printf("Stack:");
    struct Node* temp = stack->top;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}



int main(void)
{

    int n = 0;  //n*n�x�}
    while(n != -1){

        scanf("%d",&n);
        if(n == -1){break;}
        int adjacent_matrix[n][n];

        //Ū���x�}
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++ ){
                scanf("%d",&adjacent_matrix[row][col]);}}

        struct Stack stack = CreateStack();
        int SearchedAndFinishSearched[n][2];  //�Ψ��x�s�ӭ��I�������ɶ��P���������ɶ�
        //��l��
        for(int i=0; i<n; i++){
            SearchedAndFinishSearched[i][0] = 0;
            SearchedAndFinishSearched[i][1] = 0;
        }

        //DFS(���� Connected Graph)
        int index = 0;  //�j�M�_�I
        SearchedAndFinishSearched[index][0] = 1;  //�N��1���I�]���_�I
        Push(&stack,index);    //�N��1���I��Jstack����ܶ}�l����
        int order = 2;
        while(!IsEmpty(&stack)){

            int HaveNext = 0;   //�ΥH�T�{�O�_�����U�@��
            for(int i=0; i<n; i++){
                if(adjacent_matrix[index][i] > 0 && SearchedAndFinishSearched[i][0] == 0){

                    Push(&stack,i);  //�N�����I��Jstack
                    SearchedAndFinishSearched[i][0] = order;
                    order++;
                    index = i;
                    HaveNext = 1;
                    break;
                }
            }
            if(HaveNext == 0){//�P�w���e���S�����U�@���I
                //�Y���I���Ҧ��`�פw�g���������h�qstack��Pop�X���I�A�ó]�w����������
                index = Pop(&stack);    //��������
                SearchedAndFinishSearched[index][1] = order;
                order++;
                //���o�ӱ����I���e�������I���~�򱴯�
                if(!IsEmpty(&stack)){
                index = Pop(&stack);
                Push(&stack,index);}}

        }

        printf("\n");
        for(int i=0; i<n; i++){

            printf("%c:%d %d\n",i + 'a',SearchedAndFinishSearched[i][0],SearchedAndFinishSearched[i][1]);

        }









    }
    return 0;
}
