#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define max 1000

int Prim(int **graph, int* parent, int v);

// 主要取决于点，适合稠密图
// prim三部曲：1. 选距离生成树最近节点；2. 最近节点加入生成树；3. 更新minDist数组

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
    printf("%d\n",Prim(grid, parent, v));
    return 0;
}

int Prim(int** graph, int* parent, int v){
    int* minDist = (int*)malloc((v+1) * sizeof(int));
    for(int i = 0; i <= v; i++) {
        minDist[i] = max;
    }
    minDist[1] = 0;
    bool* isInTree = (bool*)calloc(v+1, sizeof(bool));  // 全为0或者false

    for (int i = 1; i < v; i++){    // 一轮加一条边
        int cur = 0;
        int minVal = max;

        for (int j = 1; j <= v; j++){   // 找到最近的点
            if (!isInTree[j] && minDist[j] < minVal){
                minVal = minDist[j];
                cur = j;
            }
        }
        isInTree[cur] = true;
        for(int j = 1; j <= v; j++){    // 更新最短距离
            if (!isInTree[j] && graph[cur][j] < minDist[j]){
                minDist[j] = graph[cur][j];
                parent[j] = cur;
            }
        }
    }
    for (int i = 1; i <= v; i++){
        printf("%d->%d\n", i, parent[i]);
    }
    int result = 0;
    for (int i = 2; i <= v; i++){
        result += minDist[i];
    }
    return result;

}