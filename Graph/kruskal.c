#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// 加边法

#define max 1000

int kruskal(int **graph, int* parent, int v);


int main(){
    int v, e;
    int x, y, k;
    scanf("%d %d",&v, &e);
    int **grid = (int**)malloc((v+1) * sizeof(int*));
    int* parent = (int*)malloc((v+1) * sizeof(int));
    for (int i = 0; i <= v; i++) {
        grid[i] = (int*)malloc((v+1) * sizeof(int));
        parent[i] = 0;
        for (int j = 0; j <= v; j++) {
            grid[i][j] = (i == j) ? 0 : max;
        }
    }

    while(e--){
        scanf("%d %d %d", &x, &y, &k);
        grid[x][y] = k;
        grid[y][x] = k;
    }
    printf("%d\n",kruskal(grid, parent, v));
    return 0;
}


