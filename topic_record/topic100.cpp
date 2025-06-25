// #include<iostream>               // DFS
// #include<vector>
// #include<algorithm>
// using namespace std;

// int dir[4][2] = {1,0, -1,0, 0,1, 0,-1};
// vector<vector<int>> graph;
// vector<vector<int>> visit;

// void dfs(int x, int y, int &index){     // 注意行列的区别
//     if(x < 0 || x >= graph.size() || y < 0 || y >= graph[0].size() || graph[x][y] == 0 || visit[x][y] != 0) return;
//     visit[x][y] = 1;
//     index++;
//     for (int i = 0; i < 4; i++){
//         int nextx = x + dir[i][0];
//         int nexty = y + dir[i][1];
//         dfs(nextx, nexty, index);
//     }
// }

// int main(){
//     int m, n;
//     cin >> m >> n;
//     graph.resize(m, vector<int>(n, 0));
//     for (int i = 0; i < m; i++){
//         for (int j = 0; j < n; j++){
//             cin >> graph[i][j];
//         }
//     }
//     visit.resize(m,vector<int>(n, 0));
//     vector<int>s;
//     int index;
    
//     for (int i = 0; i < m; i++){
//         for (int j = 0; j < n; j++){
//             index = 0;
//             dfs(i, j, index);
//             if (index != 0) s.push_back(index);
//         }
//     }
//     if (s.empty()) {
//         cout << 0 << endl;
//     } else {
//         auto max_val_it = max_element(s.begin(), s.end());
//         cout << *max_val_it << endl;
//     }
//     return 0;
// }



#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
int dir[4][2] = {1,0 ,-1,0 ,0,1 ,0,-1};

void bfs(vector<vector<int>> &graph, vector<vector<int>> &visit, int x, int y, int &s){
    queue<pair<int, int>> q;
    q.push({x,y});
    visit[x][y] = 1;        // 别漏了
    s++;
    while (!q.empty()){
        pair<int, int> loc = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            int nextx = loc.first + dir[i][0];
            int nexty = loc.second + dir[i][1];
            if (nextx < 0 || nextx >= graph.size() || nexty < 0 || nexty >= graph[0].size() || graph[nextx][nexty] == 0 || visit[nextx][nexty] != 0) continue;
            q.push({nextx, nexty});
            visit[nextx][nexty] = 1;        // 注意注意：一定要标记访问过了
            s++;
        }
    }
    
}

int main(){
    int m , n;
    cin >> m >> n;      // m是行，n是列
    vector<vector<int>> graph(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
    vector<vector<int>> visit (m, vector<int>(n, 0));
    int result = 0;
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (graph[i][j] == 1 && visit[i][j] == 0){
                int s = 0;
                bfs(graph, visit, i, j, s);
                result = max(result, s);
            }
        }
    }
    cout << result;
    return 0;
}