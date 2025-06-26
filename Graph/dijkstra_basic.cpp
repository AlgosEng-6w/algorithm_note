#include<iostream>
#include<climits>   // 方便使用INT_MAx
#include<vector>
using namespace std;

// 思路：1. 更新最近距离；2. 选定最近未访问节点
int main(){
    int vertex, edge;
    cin >> vertex >> edge;
    vector<bool>Visited(vertex+1, false);
    vector<int>minDist(vertex+1, INT_MAX);
    vector<vector<int>>grid(vertex+1, vector<int>(vertex+1, INT_MAX));

    for (int i = 1; i <= edge; i++){
        int start, end, val;
        cin >> start >> end >> val;
        grid[start][end] = val;
    }

    int cur_node = 1;
    minDist[1] = 0;
    for (int i = 1; i < vertex; i++){
        Visited[cur_node] = true;
        int j = 0;
        while (j <= vertex){
            if (Visited[j] || grid[cur_node][j]== INT_MAX || minDist[j] <= (minDist[cur_node] + grid[cur_node][j])) {
                j++;
                continue;
            }
            minDist[j] = minDist[cur_node] + grid[cur_node][j];
            j++;
        }
        cur_node = 0;
        for (int k = 1; k <= vertex; k++){
            if (!Visited[k] && minDist[k] < minDist[cur_node]) cur_node = k;
        }
    }

    if (minDist[vertex] == INT_MAX) cout << -1 << endl;
    else cout << minDist[vertex] << endl;

    return 0;
}