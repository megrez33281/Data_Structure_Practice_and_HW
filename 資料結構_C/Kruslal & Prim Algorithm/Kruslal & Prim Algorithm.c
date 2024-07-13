#include <windows.h>
#include <stdio.h>

struct Edge{
    int cost;
    //紀錄edge的兩個邊
    int u;
    int v;


};

struct Edge CreateEdge(){

    struct Edge edge;
    edge.cost = 0;
    edge.u = -1;
    edge.v = -1;
    return edge;

}

int Equal(struct Edge* edge1,struct Edge* edge2){
    //判斷邊是否相等
    return(edge1->cost == edge2->cost && ((edge1->u == edge2->u && edge1->v == edge2->v) || (edge1->v == edge2->u && edge1->u == edge2->v)));
}

void Swap(struct Edge* edge1, struct Edge* edge2){
    //交換邊之內容

    int tempCost = edge1->cost;
    int tempu = edge1->u;
    int tempv = edge1->v;
    edge1->cost = edge2->cost;
    edge1->u = edge2->u;
    edge1->v = edge2->v;
    edge2->cost = tempCost;
    edge2->u = tempu;
    edge2->v = tempv;

}


int main(void)
{

    int n = 0;  //n*n矩陣
    while(n != -1){

        scanf("%d",&n);
        if(n == -1){break;}
        int adjacent_matrix[n][n];

        //讀取矩陣
        int sumEdge = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++ ){
                scanf("%d",&adjacent_matrix[row][col]);
                if (adjacent_matrix[row][col] > 0){sumEdge++;}//紀錄邊的數目
                    }}
        sumEdge/=2;//由於每次有值大於0時皆把sumEdge+1，會導致最後每條邊被記錄兩次

        //將所有邊存入E並排序待Kruskal
        struct Edge E[sumEdge];
        for(int i=0; i<sumEdge; i++){
            E[i] = CreateEdge();
        }

        int EdgeIndex = 0;
        //因其為無向圖，只需讀取Upper Triangular
        for(int row = 0; row <= n; row++){
            for(int col = row+1; col <n; col++){
                if(adjacent_matrix[row][col] == 0){continue;}
                struct Edge edge;
                edge.cost = adjacent_matrix[row][col];
                edge.u = row;
                edge.v = col;
                E[EdgeIndex] = edge;
                EdgeIndex++;

            }

        }

        //bubble sort

        for(int i=0; i<sumEdge-1; i++){
            for(int j=0; j<sumEdge-i-1; j++){
                if(E[j].cost > E[j+1].cost || (E[j].cost == E[j+1].cost && E[j].u + E[j].v > E[j+1].u + E[j+1].v )){//後者為當cost相等時之判斷
                    Swap(&E[j],&E[j+1]);
                }
            }
        }


        //Prim
        //此處TV與先前BeChoosed運轉方式不同，TV紀錄會依序紀錄被選到的點，BeChoosed則是以其自身index作為點(如：BeChoosed中的index=0代表的是matrix中的0點，TV中的index=0則會代表第一個被記錄的點，如TV[0]=1代表第一個被選到的是1點)
        struct Edge TP[n-1]; //紀錄被選中的邊

        for(int i=0; i< n-1; i++){
            TP[i] = CreateEdge();
        }


        int TV[n]; //紀錄已選過的點
        for(int i=0; i<n; i++){TV[i] = -1;}//初始化
        int InTheTV[n];//紀錄對應index是否有被TV選取
        for(int i=0; i<n; i++){InTheTV[i] = 0;}//初始化

        TV[0] = 0; //以0為起始點
        InTheTV[TV[0]] = 1;
        int SumOfT = 0;

        while(SumOfT < n-1){
            //找到能與TV中的點組成最小cost之edge之點
            int LeastCostVertex = E[sumEdge-1].cost +1; //預設為最大值(E已sort過)
            int TVIndex = 0;
            struct Edge edge = CreateEdge();

            //尋找最小cost，以TVIndex為TV的索引
            while(TVIndex < n && TV[TVIndex] != -1){
                for(int i=0; i<n; i++){
                    if(InTheTV[i] == 1){continue;}//透過InTheTV[i]檢查i點是否在TV中
                    if((adjacent_matrix[TV[TVIndex]][i] > 0 &&adjacent_matrix[TV[TVIndex]][i] < LeastCostVertex) || (adjacent_matrix[TV[TVIndex]][i] == LeastCostVertex && edge.u + edge.v > TV[TVIndex] + i)){ //用InTheTV確認其沒有被TV選到e
                        //找到最小值，值相等時以AlphaBeta優先(u+v值較小者)
                        LeastCostVertex = adjacent_matrix[TV[TVIndex]][i];
                        //在此用u儲存TV中的點，v儲存TV外的點
                        edge.u = TV[TVIndex];
                        edge.v = i;         //記錄邊

                    }
                }

                edge.cost = adjacent_matrix[edge.u][edge.v];
                TVIndex++;
            }


            if(edge.u == -1 || edge.v == -1){break;}    //出現連接到的點=-1表示沒有找到可連接的點(點已用完)
            TP[SumOfT] = edge;
            TV[SumOfT+1] = edge.v; //將點放入TV(加入的邊與使用的點差1)
            SumOfT++;
            InTheTV[edge.v] = 1;//更新InTheTV

        }
        //printf("SumOfT:%d\n",SumOfT);
        //印出PrimCost
        int PrimCost = 0;
        for(int i=0; i<n-1; i++){
            PrimCost += TP[i].cost;
        }
        printf("Prim minimum cost:%d\n",PrimCost);


        //Kruskal
        //要點為:將邊依照cost的大小由小排到大後從最小的邊開始，若將其加入不會造成cycle就將其加入TK中
        int TK[sumEdge]; //紀錄被選中的邊之對應序號(被選中則設為1)
        //TK作為E的對照表，當TK[i]=1，代表E[i]對應之邊有被選中
        for(int i=0; i<sumEdge; i++){TK[i] = 0;}//初始化
        SumOfT = 0;//紀錄選中的邊
        for(int i=0; i<sumEdge; i++){
            if(SumOfT == n-1){break;}//最多n-1條邊

            //會造成cycle
            int IsCycle = 1;
            //藉由Prim處完成的TP來判斷加入邊後會不會變成cycle
            for(int j=0; j<n-1; j++){
                if(Equal(&E[i],&TP[j])){
                    IsCycle = 0;

                    break;}
            }
            //不會造成cycle
            if(!IsCycle){
                TK[i] = 1;   //將edge加入T
                SumOfT++;
            }
       }

        int KruskalCost = 0;
        for(int i=0; i<sumEdge; i++){
           if(TK[i] == 1){
                KruskalCost += E[i].cost;
           }

       }
        printf("Kruskal minimun cost:%d\n",KruskalCost);








    }
    return 0;
}
