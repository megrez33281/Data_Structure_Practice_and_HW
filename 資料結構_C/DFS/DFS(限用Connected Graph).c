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

    //stack為空
    if(stack->top == NULL){
        stack->top = node;
        stack->top->next = NULL; //設置結尾
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

    int n = 0;  //n*n矩陣
    while(n != -1){

        scanf("%d",&n);
        if(n == -1){break;}
        int adjacent_matrix[n][n];

        //讀取矩陣
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++ ){
                scanf("%d",&adjacent_matrix[row][col]);}}

        struct Stack stack = CreateStack();
        int SearchedAndFinishSearched[n][2];  //用來儲存個個點的探索時間與結束探索時間
        //初始化
        for(int i=0; i<n; i++){
            SearchedAndFinishSearched[i][0] = 0;
            SearchedAndFinishSearched[i][1] = 0;
        }

        //DFS(限用 Connected Graph)
        int index = 0;  //搜尋起點
        SearchedAndFinishSearched[index][0] = 1;  //將第1個點設為起點
        Push(&stack,index);    //將第1個點丟入stack中表示開始探索
        int order = 2;
        while(!IsEmpty(&stack)){

            int HaveNext = 0;   //用以確認是否有找到下一個
            for(int i=0; i<n; i++){
                if(adjacent_matrix[index][i] > 0 && SearchedAndFinishSearched[i][0] == 0){

                    Push(&stack,i);  //將對應點放入stack
                    SearchedAndFinishSearched[i][0] = order;
                    order++;
                    index = i;
                    HaveNext = 1;
                    break;
                }
            }
            if(HaveNext == 0){//判定先前有沒有找到下一個點
                //若該點之所有深度已經探索完畢則從stack中Pop出該點，並設定為探索完畢
                index = Pop(&stack);    //探索完成
                SearchedAndFinishSearched[index][1] = order;
                order++;
                //取得該探索點之前探索的點並繼續探索
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
