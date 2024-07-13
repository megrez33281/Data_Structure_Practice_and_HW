#include <windows.h>
#include <stdio.h>

struct Edge{
    int cost;
    //����edge�������
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
    //�P�_��O�_�۵�
    return(edge1->cost == edge2->cost && ((edge1->u == edge2->u && edge1->v == edge2->v) || (edge1->v == edge2->u && edge1->u == edge2->v)));
}

void Swap(struct Edge* edge1, struct Edge* edge2){
    //�洫�䤧���e

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

    int n = 0;  //n*n�x�}
    while(n != -1){

        scanf("%d",&n);
        if(n == -1){break;}
        int adjacent_matrix[n][n];

        //Ū���x�}
        int sumEdge = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++ ){
                scanf("%d",&adjacent_matrix[row][col]);
                if (adjacent_matrix[row][col] > 0){sumEdge++;}//�����䪺�ƥ�
                    }}
        sumEdge/=2;//�ѩ�C�����Ȥj��0�ɬҧ�sumEdge+1�A�|�ɭP�̫�C����Q�O���⦸

        //�N�Ҧ���s�JE�ñƧǫ�Kruskal
        struct Edge E[sumEdge];
        for(int i=0; i<sumEdge; i++){
            E[i] = CreateEdge();
        }

        int EdgeIndex = 0;
        //�]�䬰�L�V�ϡA�u��Ū��Upper Triangular
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
                if(E[j].cost > E[j+1].cost || (E[j].cost == E[j+1].cost && E[j].u + E[j].v > E[j+1].u + E[j+1].v )){//��̬���cost�۵��ɤ��P�_
                    Swap(&E[j],&E[j+1]);
                }
            }
        }


        //Prim
        //���BTV�P���eBeChoosed�B��覡���P�ATV�����|�̧Ǭ����Q��쪺�I�ABeChoosed�h�O�H��ۨ�index�@���I(�p�GBeChoosed����index=0�N���Omatrix����0�I�ATV����index=0�h�|�N��Ĥ@�ӳQ�O�����I�A�pTV[0]=1�N��Ĥ@�ӳQ��쪺�O1�I)
        struct Edge TP[n-1]; //�����Q�襤����

        for(int i=0; i< n-1; i++){
            TP[i] = CreateEdge();
        }


        int TV[n]; //�����w��L���I
        for(int i=0; i<n; i++){TV[i] = -1;}//��l��
        int InTheTV[n];//��������index�O�_���QTV���
        for(int i=0; i<n; i++){InTheTV[i] = 0;}//��l��

        TV[0] = 0; //�H0���_�l�I
        InTheTV[TV[0]] = 1;
        int SumOfT = 0;

        while(SumOfT < n-1){
            //����PTV�����I�զ��̤pcost��edge���I
            int LeastCostVertex = E[sumEdge-1].cost +1; //�w�]���̤j��(E�wsort�L)
            int TVIndex = 0;
            struct Edge edge = CreateEdge();

            //�M��̤pcost�A�HTVIndex��TV������
            while(TVIndex < n && TV[TVIndex] != -1){
                for(int i=0; i<n; i++){
                    if(InTheTV[i] == 1){continue;}//�z�LInTheTV[i]�ˬdi�I�O�_�bTV��
                    if((adjacent_matrix[TV[TVIndex]][i] > 0 &&adjacent_matrix[TV[TVIndex]][i] < LeastCostVertex) || (adjacent_matrix[TV[TVIndex]][i] == LeastCostVertex && edge.u + edge.v > TV[TVIndex] + i)){ //��InTheTV�T�{��S���QTV���e
                        //���̤p�ȡA�Ȭ۵��ɥHAlphaBeta�u��(u+v�ȸ��p��)
                        LeastCostVertex = adjacent_matrix[TV[TVIndex]][i];
                        //�b����u�x�sTV�����I�Av�x�sTV�~���I
                        edge.u = TV[TVIndex];
                        edge.v = i;         //�O����

                    }
                }

                edge.cost = adjacent_matrix[edge.u][edge.v];
                TVIndex++;
            }


            if(edge.u == -1 || edge.v == -1){break;}    //�X�{�s���쪺�I=-1��ܨS�����i�s�����I(�I�w�Χ�)
            TP[SumOfT] = edge;
            TV[SumOfT+1] = edge.v; //�N�I��JTV(�[�J����P�ϥΪ��I�t1)
            SumOfT++;
            InTheTV[edge.v] = 1;//��sInTheTV

        }
        //printf("SumOfT:%d\n",SumOfT);
        //�L�XPrimCost
        int PrimCost = 0;
        for(int i=0; i<n-1; i++){
            PrimCost += TP[i].cost;
        }
        printf("Prim minimum cost:%d\n",PrimCost);


        //Kruskal
        //�n�I��:�N��̷�cost���j�p�Ѥp�ƨ�j��q�̤p����}�l�A�Y�N��[�J���|�y��cycle�N�N��[�JTK��
        int TK[sumEdge]; //�����Q�襤���䤧�����Ǹ�(�Q�襤�h�]��1)
        //TK�@��E����Ӫ�A��TK[i]=1�A�N��E[i]�������䦳�Q�襤
        for(int i=0; i<sumEdge; i++){TK[i] = 0;}//��l��
        SumOfT = 0;//�����襤����
        for(int i=0; i<sumEdge; i++){
            if(SumOfT == n-1){break;}//�̦hn-1����

            //�|�y��cycle
            int IsCycle = 1;
            //�ǥ�Prim�B������TP�ӧP�_�[�J���|���|�ܦ�cycle
            for(int j=0; j<n-1; j++){
                if(Equal(&E[i],&TP[j])){
                    IsCycle = 0;

                    break;}
            }
            //���|�y��cycle
            if(!IsCycle){
                TK[i] = 1;   //�Nedge�[�JT
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
