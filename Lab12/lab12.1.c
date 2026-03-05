#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *Dijkstra(int *L, int n) {
    int *dist = (int*)malloc(n * sizeof(int));
    int *visited = (int*)malloc(n * sizeof(int));
    int i, j, min, u;

    for(i = 0; i < n; i++){
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[0] = 0;

    for(i = 0; i < n-1; i++) {

        min = INT_MAX;

        for(j = 0; j < n; j++){
            if(!visited[j] && dist[j] <= min){
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for(j = 0; j < n; j++){
            if(!visited[j] &&
               L[u*n + j] &&
               dist[u] != INT_MAX &&
               dist[u] + L[u*n + j] < dist[j]) {

                dist[j] = dist[u] + L[u*n + j];
            }
        }
    }

    return dist;
}

int main() {

    int n = 5, i, j;
    int *d, *g;

    g = (int*)malloc(n*n*sizeof(int));

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            g[i*n+j]=0;

    g[0*n+1]=10;
    g[0*n+2]=8;
    g[0*n+3]=30;
    g[0*n+4]=100;

    g[1*n+2]=20;

    g[3*n+1]=20;
    g[3*n+2]=20;

    g[4*n+3]=18;

    d = Dijkstra(g,n);

    for(i=1;i<n;i++)
        printf("%d ", d[i]);

    return 0;
}