#include <stdio.h>
#include <stdlib.h>

int *KnapsackDP(int *w, int *v, int n, int wx){

    int i,j;

    int K[n+1][wx+1];

    for(i=0;i<=n;i++){
        for(j=0;j<=wx;j++){

            if(i==0 || j==0)
                K[i][j]=0;

            else if(w[i-1] <= j){

                int a = v[i-1] + K[i-1][j-w[i-1]];
                int b = K[i-1][j];

                K[i][j] = (a>b)?a:b;
            }

            else
                K[i][j] = K[i-1][j];
        }
    }

    int *x = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++) x[i]=0;

    j = wx;

    for(i=n;i>0;i--){
        if(K[i][j] != K[i-1][j]){
            x[i-1] = 1;
            j = j - w[i-1];
        }
    }

    return x;
}

int main(){

    int n = 5 , wx = 11;

    int w[5]={1,2,5,6,7};
    int v[5]={1,6,18,22,28};

    int *x;

    x = KnapsackDP(w,v,n,wx);

    for(int i=0;i<n;i++)
        printf("%d",x[i]);

    return 0;
}