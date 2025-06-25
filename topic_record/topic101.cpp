#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int dir[4][2] = {1,0,-1,0,0,1,0,-1};

void dfs(int x, int y, vector<vector<int>> &graph, vector<vector<int>> &visit, int &tem){
    if (x < 0 || y < 0 || x >= graph.size() || y >= graph[0].size() || graph[x][y] == 0 || visit[x][y] == 1 ){
        return;     // 注意x的范围是0到size减1
    }
    if (x == 0 || y == 0 || x == graph.size()-1 || y == graph[0].size()-1) tem = -1;
    visit[x][y] = 1;
    if (tem != -1) tem++;
    for(int i =  0; i < 4; i++){
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        dfs(nextx, nexty, graph, visit, tem);
    }
}

void bfs(int x, int y, vector<vector<int>> &graph, vector<vector<int>> &visit, int &tem){
    if (x < 0 || y < 0 || x >= graph.size() || y >= graph[0].size() || graph[x][y] == 0 || visit[x][y] == 1 ){
        return;
    }
    if (x == 0 || y == 0 || x == graph.size()-1 || y == graph[0].size()-1) tem = -1;
    queue<pair<int, int>> q;
    visit[x][y] = 1;
    q.push({x,y});
    if (tem != -1) tem++;
    while(!q.empty()){
        pair<int, int> l = q.front();
        q.pop();
        for(int i =  0; i < 4; i++){
            int nextx = l.first + dir[i][0];
            int nexty = l.second + dir[i][1];
            if (nextx < 0 || nexty < 0 || nextx >= graph.size() || nexty >= graph[0].size() || graph[nextx][nexty] == 0 || visit[nextx][nexty] == 1 ){
                continue;
            }
            if (nextx == 0 || nexty == 0 || nextx == graph.size()-1 || nexty == graph[0].size()-1) tem = -1;
            visit[nextx][nexty] = 1;
            q.push({nextx, nexty});
            if (tem != -1) tem++;
        } 
    }
}

int main(){
    int m, n;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }
    vector<vector<int>> visit(n, vector<int>(m, 0));
    int result = 0;     // 注意要先定义初始值，在C++中，局部变量不会自动初始化为0，其初始值是内存中的残留数据（可能是任意值）。
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (graph[i][j] == 0 || visit[i][j] == 1) continue;
            int tem = 0;
            // dfs(i, j, graph, visit, tem);
            bfs(i, j, graph, visit, tem);
            if (tem != -1) result += tem;
        }
    }
    cout << result;
    return 0;
}