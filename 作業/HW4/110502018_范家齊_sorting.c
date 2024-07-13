#include <windows.h>
#include <stdio.h>



void BubbleSort(int* numberArray, int sum){
    //��ǤJ��array�i��BubbleSort
    //BubbleSort����z���M��array�A�C���Y��e�Ȥp��U�@�ȡA�N��̥洫
    //�`�N�]���|Ū����U�@�ȡA�M���ɥu��sum-1
    //����k�C�M���@�M�|�N�̤j�ȩ��̫᭱�A�G�u������M���A�B�C���N�M������-1
    //�@�ݹM��sum-1��(���ܾ����׬�2������Y�����ƦC)
    int switched = 1;   //�ΥH�d�ݦb���^��B�O�_���g�L�Ȫ��洫

    for(int i=0; i<sum-1 && switched == 1; i++){//�Y�g�L���j���switched=0��ܸg�L�@�餺�j���S������Ȫ��洫�A�N��0 <= j < sum-i-1���d�򤺶��Ǭҥ��T
        switched = 0;   //�w�]�S���洫
        for(int j=0; j<sum-i-1; j++){
            if(*(numberArray + j) > *(numberArray+j+1)){
                int temp = *(numberArray +j);
                *(numberArray + j) = *(numberArray + j + 1);
                *(numberArray + j + 1) = temp;
                switched = 1; //���洫

            }
        }
    }

}

void QuickSort(int* numberArray, int left, int right){
    //��ǤJ��array�i��QuickSort
    /*��z���barray���]�w�@�Ӱ���I�öi�滼�j
    �C�����j�N�Ҧ��p�����I���ȥ�����I�k��A�j�����I���ȥ�����I����
    �b���]array�����̥��䬰����I�A�ä��O�qarray����(���N�z�H)�B�k(�k�N�z�H)�ⰼ�}�l�M��A���N�z�H���j�����I���ȫᰱ��A�k�N�z�H���p�����I���ȫᰱ��
    ��ӥN�z�H�������N��̤��Ȥ���
    ���̬۹J�ɡA�N����I�P�ۻP���I���ȶi��洫
    �ѩ����I��barray�̥���A�洫��n�ϳ̥��䪺�Ȩ��¤p�����I�A�G�ݭn�k�N�z�H�u���}�l�M��A�T�O��b�J�쥪�N�z�H�e���Ҧ��p�����I���ȡA�]�קK���N�z�H�P�k�N�z�H�۹J�ɤ��Ȥj�����I
    �b�k�N�z�H���檺���p�U��N�z�H�۹J�����p���G(1)�k�N�z�H���p�����I���ȫᰱ��óQ���N�z�H�J��C(2)�k�N�z�H�����J�쥪�N�z�H�ð���
    (1)�����ΫO�Ҩ�ӥN�z�H�۹J���I���p�����I����
    (2)�����p�h�ѩ󥪥N�z�H���°��d�b�W�@���洫�᪺��m�A���N�z�H���Ȧ��ɬ��p�����I����
    �ⱡ�p�ҫO�Ұ���I�P�۹J�I�洫�����I�������ȬҤp�����I�A����I�k�����ȬҤj�����I
    �N����I�����������P�k���������A���O��J���j
    ���򻼰j��A��J��array�ȷ|�V�ӶV�p����_�I��m�j����I��m�����εo�ͮɪ�^(�}�C����<1)
    �Y�}�C���׵���1�A���N�z�H�P�k�N�z�H�@�}�l�Y�۹J�A�ä��O��J(�}�C�̥���,����I��m-1)�P(����I��m+1,�}�C�̥k����m)
    �o�Ͱ_�I��m�j����I��m�����p�A�G�����εo�ͮɧY�i��^*/

    if(!(left > right)){
        int i = left;  //���N�z
        int j = right; //�k�N�z
        int pivot = *(numberArray + left);

        while(i != j){
            //�k�N�z�����ʡA���p�����I����
            while(*(numberArray+j) >= pivot && i!=j){
                j--;
            }

            //���N�z���ʡA���j�����I����
            while(*(numberArray + i) <= pivot && i!= j){
                i++;
            }

            //�Y��̬��۹J�A�i��洫(�Y�۹J�h�|�P����I�洫)
            if(i != j){
                //�洫
                int temp = *(numberArray + i);
                *(numberArray + i) = *(numberArray + j);
                *(numberArray + j) = temp; }
            }


        //���ɥ��N�z�P�k�N�z�B��۹J���A

        //�P����I�洫
        *(numberArray + left) = *(numberArray + j);
        *(numberArray + j) = pivot;


        //�������j
        //�i�J���j
        QuickSort(numberArray,left,i-1);
        QuickSort(numberArray,j+1,right);//����i=j

        }

}

int main(){


    int n = 0;

    while(scanf("%d",&n)){
        if(n == -1){break;}
        int NumArrayForBubble[n];
        int NumArrayForQuick[n];
        for(int i=0; i<n; i++){
            scanf("%d",&NumArrayForBubble[i]);
            NumArrayForQuick[i] = NumArrayForBubble[i];
        }

        //�ޥ�time.h��clock()�i��p�ɡAclock()�|��^�{���}�l��I�s�ɤ��ɶ�


        LARGE_INTEGER t1, t2, ts;
        QueryPerformanceFrequency(&ts);
        QueryPerformanceCounter(&t1);
        BubbleSort(NumArrayForBubble,n);//�I�sBubbleSort
        QueryPerformanceCounter(&t2);
        for(int i=0; i<n; i++){
            printf("%d ",NumArrayForBubble[i]);
        }
        printf("\n");
        double BubbleCost = (t2.QuadPart-t1.QuadPart)/(double)(ts.QuadPart);

        QueryPerformanceFrequency(&ts);
        QueryPerformanceCounter(&t1);
        QuickSort(NumArrayForQuick,0,n-1);  //�I�sQuickSort
        QueryPerformanceCounter(&t2);

        printf("bubble sort : %.7lfsec\n", BubbleCost);
        printf("quick sort : %.7lfsec\n",(t2.QuadPart-t1.QuadPart)/(double)(ts.QuadPart));





    }

;
    return 0;
}
