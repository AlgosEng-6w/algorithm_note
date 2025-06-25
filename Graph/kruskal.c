#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int l;
    int r;
    int val;
}edge;

int partition(int l, int r, edge* grid);
void quick_sort(int l, int r, edge* grid);
int find(int node, int* father);
bool isSame(int node1, int node2, int* father);
int kruskal(int e, int v, edge* grid, int* father);


int main(){
    int v, e;
    scanf("%d %d", &v, &e);
    int* father = (int*)malloc((v+1) * sizeof(int));
    for (int i = 0; i <= v; i++){
        father[i] = i;
    }
    edge* grid = (edge*)malloc(e * sizeof(edge));
    for(int i = 0; i < e; i++) {
        scanf("%d %d %d",&grid[i].l, &grid[i].r, &grid[i].val);
    }
    printf("%d\n", kruskal(e, v, grid, father));
    return 0;
}

int kruskal(int e, int v, edge* grid, int* father){
    int result = 0;
    // 1. 对所有边进行权值排序
    quick_sort(0, e-1, grid);

    int e_count = 0;
    // 2. 依次加边
    for(int i = 0; i < e; i++){
        int node1 = grid[i].l;
        int node2 = grid[i].r;
        // 3. 查是否已加入该节点
        if (isSame(node1, node2, father)){
            e_count++;
            result += grid[i].val;
        }
        if (e_count == v-1) break;
    }

    return result;
}

int find(int node, int* father){
    return node == father[node] ? node : (father[node] = find(father[node], father));   // 三元表达式记得加括号
}

bool isSame(int node1, int node2, int* father){
    node1 = find(node1, father);
    node2 = find(node2, father);
    if (node1 == node2) return false;
    else{
        father[node2] = node1;
        return true;
    }
}

int partition(int l, int r, edge* grid){
    int i = l-1;
    int cur = grid[r].val;
    for (int j = l; j <= r; j++){
        if (grid[j].val > cur) continue;
        i++;
        edge temp = grid[i];     // 注意交换整个结构体
        grid[i] = grid[j];
        grid[j] = temp;
    }
    return i;
}

void quick_sort(int l, int r, edge* grid){
    if (r <= l) return;
    int middle = partition(l, r, grid);
    quick_sort(l, middle-1, grid);
    quick_sort(middle+1, r, grid);
}