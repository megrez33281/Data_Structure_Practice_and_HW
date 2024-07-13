#include <windows.h>
#include <stdio.h>

void BubbleSort(int x[], int n){

    int i,j,temp,searched;
    searched = 1;
    for(i=n-1; i>=0 && searched == 1; i--){
        searched = 0;
        for(j=0; j<i; j++){
            if(x[j] > x[j+1]){
                temp = x[j+1];
                x[j+1] = x[j];
                x[j] = temp;
                searched = 1;
            }
        }
    }


}

void SelectSort(int x[], int n){

    int i,j,large,largeIndex;

    for(i=n-1; i>0; i--){
        largeIndex = 0;
        large = x[0];
        for(j=1; j<=i; j++){
            if(x[j] > large){
                large = x[j];
                largeIndex = j;
            }
        }
        x[largeIndex] = x[i];
        x[i] = large;


    }



}

void InsertionSort(int x[], int n){
    //�Narray�����ƧǻP���ƧǨⳡ��

    int i,j,inserted;

    //index = 0
    for(i=1; i<n; i++){
        inserted = x[i]; //�n���J���Ʀr
                         //��index = i ���Ů�
                         //�Nj�]���Ů楪��@��
        for(j=i-1; j>=0 && x[j] > inserted; j--){
            x[j+1] = x[j]; //���ʪŮ�
        }
        x[j+1] = inserted;   //���J�Ʀr


    }




}


void Partition(int x[], int lb, int ub, int* pivot){

    int left,right,tempPivot,temp;
    left = lb;
    right = ub;
    tempPivot = x[lb];

    while(left != right){

        while(x[right] > tempPivot && left != right){
            right--;
        }

        //�`�N���N�z�|�J��pivot�A�P�_���n�[�J"="
        while(x[left] <= tempPivot && left != right){
            left ++;
        }

        if(left != right){
            temp = x[left];
            x[left] = x[right];
            x[right] = temp;

        }
    }

    //�洫pivot
    x[lb] = x[left];
    x[left] = tempPivot;
    *pivot = left;

}

void QuickSort(int x[], int lb, int ub){
    int j;
    if(lb >= ub){
        return ;
    }
    //�]�mpivot
    Partition(x,lb,ub,&j);

    QuickSort(x,lb,j-1);
    QuickSort(x,j+1,ub);



}


int main(){

    int n = 0;
    while(n != -1){
        scanf("%d",&n);
        if(n == -1){break;}

        int x[n];
        for(int i=0; i<n; i++){
            scanf("%d",&x[i]);
            }
        QuickSort(x,0,n-1);

        for(int i=0; i<n; i++){
            printf("%d ",x[i]);
            }
        printf("\n");

    }



    return 0;
}
