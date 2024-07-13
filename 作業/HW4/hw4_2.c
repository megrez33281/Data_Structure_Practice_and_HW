#include <time.h>
#include <stdio.h>
#include<malloc.h>
#define swap(x,y) {int t; t = x; x = y; y = t;}

void bubbleSort(int x[], int n){
	int i, j, temp;
	for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - 1 - i; j++){
            if (x[j] > x[j + 1]){
				swap(x[j], x[j + 1]);
			}
        }
	}
}

void partition(int x[], int lb, int ub, int *pj) {
    int a, down, up;

    a = x[lb];

    up = ub;
    down = lb;
    while(down < up){
        while(x[down] <= a && down < ub)
            down++;
        while(x[up] > a)
            up--;
        if(down < up){
            swap(x[up], x[down]);
        }
    }
    x[lb] = x[up];
    x[up] = a;
    *pj = up;
}

void quickSort(int x[], int lb, int ub) {
    int j;
    if(lb >= ub)
        return;
    partition(x, lb, ub, &j);
    quickSort(x, lb, j-1);
    quickSort(x, j+1, ub);
}

int main(){

    int max, i, j;

	while(1){
		scanf("%d",&max);
		if(max == -1)
			break;

	    int *arr_b = malloc(max*sizeof(int));
	    int *arr_q = malloc(max*sizeof(int));

	    for(i=0;i<max;i++){
	        scanf("%d",&arr_b[i]);
	    }

	    for(i=0;i<max;i++){
	        arr_q[i] = arr_b[i];
	    }

	    clock_t start_b, end_b, start_q, end_q;
	    double total_b, total_q;

	    start_b = clock();
	    bubbleSort(arr_b, max);
	    end_b = clock();

	    total_b = (double)(end_b - start_b) / CLOCKS_PER_SEC;

	    start_q = clock();
	    quickSort(arr_q, 0, max-1);
	    end_q = clock();

	    total_q = (double)(end_q - start_q) / CLOCKS_PER_SEC;

	    for(i=0;i<max;i++){
	        printf("%d ",arr_q[i]);
		}

	    printf("\nBubble sort:%f sec", total_b);
	    printf("\nQuick sort:%f sec\n", total_q);

	    free(arr_b);
	    free(arr_q);
	}
   	return(0);
}
