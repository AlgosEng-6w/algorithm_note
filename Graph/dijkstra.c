#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 100000

// 第一步，选源点到哪个节点近且该节点未被访问过
// 第二步，该最近节点被标记访问过
// 第三步，更新非访问节点到源点的距离

typedef struct{
    int start;
    int end;
    int value;
}edge;

void bubble_sort(edge* grid, int m);

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    edge* grid = (edge*)malloc(m * sizeof(edge));
    for (int i = 0; i < m; i++){
        scanf("%d %d %d", &grid[i].start, &grid[i].end, &grid[i].value);
    }
    bubble_sort(grid, m);   // 对图进行初始化和整理

    int* minDist = (int*)calloc((n+1), sizeof(int));
    bool* isIn = (bool*)calloc((n+1), sizeof(bool));
    isIn[1] = true;
    for (int i = 1; i <= n; i++){
        minDist[i] = max;
    }       // 初始化最小距离和判定数组

    int cur_edge = 1;
    for (int i = 1; i <= n; i++){       // 加入n个节点
        int j = 0;
        while(j < m && grid[j].start != cur_edge) j++;
        while(grid[j].start == cur_edge){
            if (minDist[grid[j].end] > (grid[j].value + minDist[cur_edge])){
                minDist[grid[j].end] = grid[j].value + minDist[cur_edge];
            }
            j++;
        }       // 从新节点更新minDist数组

        int cur_value = max;
        for (int i = 1; i <= n; i++){
            if (!isIn[i] && minDist[i] < cur_value){
                cur_edge = i;
                cur_value = minDist[i];
            }
        }
        isIn[cur_edge] = true;      // 加入最近节点

    }

    printf("%d\n", minDist[n+1]);
    
    return 0;
}

void bubble_sort(edge* grid, int m){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m-i-1; j++){
            if (grid[j].start > grid[j+1].start){
                edge temp = grid[j];
                grid[j] = grid[j+1];
                grid[j+1] = temp;
            }
        }
    }
}
