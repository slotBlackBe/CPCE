#include <stdio.h>
#include <stdlib.h>

int *KnapsackGreedy(int *w, int *v, int n, int wx){

    int *x = (int*)malloc(n*sizeof(int));
    float ratio[n];
    int i,j;

    for(i=0;i<n;i++){
        x[i]=0;
        ratio[i]=(float)v[i]/w[i];
    }

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(ratio[i] < ratio[j]){
                float tr = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = tr;

                int tw = w[i];
                w[i] = w[j];
                w[j] = tw;

                int tv = v[i];
                v[i] = v[j];
                v[j] = tv;
            }
        }
    }

    int weight = 0;

    for(i=0;i<n;i++){
        if(weight + w[i] <= wx){
            x[i] = 1;
            weight += w[i];
        }
    }

    return x;
}

int main(){

    int n = 5, wx = 11;

    int w[5]={1,2,5,6,7};
    int v[5]={1,6,18,22,28};

    int *x = KnapsackGreedy(w,v,n,wx);

    for(int i=0;i<n;i++)
        printf("%d ",x[i]);

    return 0;
}