#include <windows.h>
#include <stdio.h>



void BubbleSort(int* numberArray, int sum){
    //對傳入的array進行BubbleSort
    //BubbleSort之原理為遍歷array，每次若當前值小於下一值，將兩者交換
    //注意因為會讀取到下一值，遍歷時只到sum-1
    //此方法每遍歷一遍會將最大值放到最後面，故只須持續遍歷，且每次將遍歷長度-1
    //共需遍歷sum-1次(當變歷長度為2完成後即完成排列)
    int switched = 1;   //用以查看在內回圈處是否有經過值的交換

    for(int i=0; i<sum-1 && switched == 1; i++){//若經過內迴圈後switched=0表示經過一圈內迴圈後沒有任何值的交換，代表0 <= j < sum-i-1的範圍內順序皆正確
        switched = 0;   //預設沒有交換
        for(int j=0; j<sum-i-1; j++){
            if(*(numberArray + j) > *(numberArray+j+1)){
                int temp = *(numberArray +j);
                *(numberArray + j) = *(numberArray + j + 1);
                *(numberArray + j + 1) = temp;
                switched = 1; //有交換

            }
        }
    }

}

void QuickSort(int* numberArray, int left, int right){
    //對傳入的array進行QuickSort
    /*原理為在array中設定一個基準點並進行遞迴
    每次遞迴將所有小於基準點的值丟到基準點右邊，大於基準點的值丟到基準點左邊
    在此設array中的最左邊為基準點，並分別從array的左(左代理人)、右(右代理人)兩側開始尋找，左代理人找到大於基準點的值後停止，右代理人找到小於基準點的值後停止
    兩個代理人接停止後將兩者之值互換
    當兩者相遇時，將基準點與相與之點的值進行交換
    由於基準點放在array最左邊，交換後要使最左邊的值依舊小於基準點，故需要右代理人優先開始尋找，確保其在遇到左代理人前找到所有小於基準點的值，也避免左代理人與右代理人相遇時之值大於基準點
    在右代理人先行的情況下兩代理人相遇的情況有：(1)右代理人找到小於基準點的值後停止並被左代理人遇到。(2)右代理人直接遇到左代理人並停止
    (1)的情形保證兩個代理人相遇的點為小於基準點之值
    (2)的情況則由於左代理人依舊停留在上一次交換後的位置，左代理人的值此時為小於基準點之值
    兩情況皆保證基準點與相遇點交換後基準點左側的值皆小於基準點，基準點右側的值皆大於基準點
    將基準點左側的部分與右側的部分再分別丟入遞迴
    持續遞迴後，輸入的array值會越來越小直到起點位置大於終點位置的情形發生時返回(陣列長度<1)
    若陣列長度等於1，左代理人與右代理人一開始即相遇，並分別丟入(陣列最左側,基準點位置-1)與(基準點位置+1,陣列最右側位置)
    發生起點位置大於終點位置之情況，故當此情形發生時即可返回*/

    if(!(left > right)){
        int i = left;  //左代理
        int j = right; //右代理
        int pivot = *(numberArray + left);

        while(i != j){
            //右代理先移動，找到小於基準點之值
            while(*(numberArray+j) >= pivot && i!=j){
                j--;
            }

            //左代理移動，找到大於基準點之值
            while(*(numberArray + i) <= pivot && i!= j){
                i++;
            }

            //若兩者為相遇，進行交換(若相遇則會與基準點交換)
            if(i != j){
                //交換
                int temp = *(numberArray + i);
                *(numberArray + i) = *(numberArray + j);
                *(numberArray + j) = temp; }
            }


        //此時左代理與右代理處於相遇狀態

        //與基準點交換
        *(numberArray + left) = *(numberArray + j);
        *(numberArray + j) = pivot;


        //完成分隔
        //進入遞迴
        QuickSort(numberArray,left,i-1);
        QuickSort(numberArray,j+1,right);//此時i=j

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

        //引用time.h之clock()進行計時，clock()會返回程式開始到呼叫時之時間


        LARGE_INTEGER t1, t2, ts;
        QueryPerformanceFrequency(&ts);
        QueryPerformanceCounter(&t1);
        BubbleSort(NumArrayForBubble,n);//呼叫BubbleSort
        QueryPerformanceCounter(&t2);
        for(int i=0; i<n; i++){
            printf("%d ",NumArrayForBubble[i]);
        }
        printf("\n");
        double BubbleCost = (t2.QuadPart-t1.QuadPart)/(double)(ts.QuadPart);

        QueryPerformanceFrequency(&ts);
        QueryPerformanceCounter(&t1);
        QuickSort(NumArrayForQuick,0,n-1);  //呼叫QuickSort
        QueryPerformanceCounter(&t2);

        printf("bubble sort : %.7lfsec\n", BubbleCost);
        printf("quick sort : %.7lfsec\n",(t2.QuadPart-t1.QuadPart)/(double)(ts.QuadPart));





    }

;
    return 0;
}
