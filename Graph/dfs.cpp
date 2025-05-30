#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>> result;     // 第一步：确认递归函数的参数
vector<int>path;

void dfs(const vector<vector<int>>& graph, int x, int n){   // 引用以避免深拷贝

    if (x == n){        // 确认终止条件
        result.push_back(path);
        return;
    }
    
    for(int i = 1; i <= n; i++){        // 处理目前搜索节点出发的路径
        if(graph[x][i] == 1){
            path.push_back(i);
            dfs(graph, i, n);
            path.pop_back();
        }
    }
}


// 模板
// void dfs(参数) {
//     处理节点
//     dfs(图，选择的节点); // 递归
//     回溯，撤销处理结果
// }