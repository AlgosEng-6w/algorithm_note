#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define max 10000

int main(){
    int v, e;
    scanf("%d %d", &v, &e);
    int** grid = (int**)malloc((v+1) * sizeof(int*));
    int* isInTree = (int*)calloc(v+1, sizeof(int));
    // int* parent = (int*)calloc(v+1, sizeof(int));
    int* minDist = (int*)malloc((v+1) * sizeof(int));

    for (int i = 1; i <= v; i++){
        grid[i] = (int*)malloc((v+1)* sizeof(int));
        minDist[i] = max;
        for (int j = 1; j <= v; j++){
            grid[i][j] = max;
        }
    }
    minDist[1] = 0;
    int result = 0;

    while(e--){
        int v1, v2, val;
        scanf("%d %d %d", &v1, &v2, &val);
        grid[v1][v2] = val;
        grid[v2][v1] = val;
    }


    for (int i = 1; i <= v; i++){
        int cur = 0;
        int len = max;
        for (int j = 1; j <= v; j++){
            if (!isInTree[j] && minDist[j] < len){
                len = minDist[j];
                cur = j;
            }
        }
        isInTree[cur] = true;
        result += len;
        for (int j = 1; j <= v; j++){
            if (!isInTree[j] && minDist[j] > grid[cur][j]){
                minDist[j] = grid[cur][j];
                // parent[j] = cur;
            }
        }
    }
    // for(int i = 2; i <= v; i++){
    //     result += minDist[i];
    // }
    printf("%d\n", result);

    return 0;
}