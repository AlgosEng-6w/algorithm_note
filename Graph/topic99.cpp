// #include<iostream>
// #include<vector>

// using namespace std;


// void solution (const vector<vector<int>> &graph, vector<vector<int>> &status, int x, int y, int &index, int m, int n){
//     if (x < 0 || x >= n || y >= m || y < 0 || graph[x][y] != 1 || status[x][y] != 0) return;
//     status[x][y] = index;
//     solution(graph, status, x-1, y, index, m, n);
//     solution(graph, status, x+1, y, index, m, n);
//     solution(graph, status, x, y-1, index, m, n);
//     solution(graph, status, x, y+1, index, m, n);
// }

// int main(){
//     int N, M;
//     cin >> N >> M;
//     vector<vector<int>> graph(N, vector<int>(M));
//     vector<vector<int>> status(N, vector<int>(M, 0));
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < M; j++) {
//             cin >> graph[i][j];
//         }
//     }
//     int index = 0;
//     for (int i = 0; i < N; i++){
//         for (int j = 0; j < M; j++){
//             if (graph[i][j] == 1 && status[i][j] == 0){
//                 index++;
//                 solution(graph, status, i, j, index, M, N);
//             }
//         }
//     }
//     cout << index;
//     return 0;
// }                // 原创dfs

#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void fbs(const vector<vector<int>> &graph, vector<vector<int>> &status, int x, int y){
    queue<pair<int, int>> q;
    q.push({x,y});
    while (!q.empty()){
        pair<int, int>cur = q.front();
        q.pop();
        int curx = cur.first;
        int cury = cur.second;
        for(int i = 0; i < 4; i++){
            int nextx = curx + dir[i][0];
            int nexty = cury + dir[i][1];
            if (nextx < 0 || nextx >= graph.size() || nexty < 0 || nexty >= graph[0].size() || graph[nextx][nexty] == 0 || status[nextx][nexty] != 0) continue;
            q.push({nextx, nexty});
            status[nextx][nexty] = 1;   
        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> graph(N, vector<int>(M));
    vector<vector<int>> status(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    int index = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (graph[i][j] == 1 && status[i][j] == 0){
                index++;
                fbs(graph, status, i, j);
            }
        }
    }
    cout << index;

    return 0;
}