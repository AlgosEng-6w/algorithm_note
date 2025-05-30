#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> result;
vector<int> path;

void backtracking(int n, int k, int startIndex){        // 回溯法第一步：定义返回值和参数
    
    if(path.size() == k){       // 回溯法第二步：定义终止条件
        result.push_back(path);
        return;
    }

    for(int i = startIndex; i <= n; i++){        // 回溯法第三步：单层搜索的过程
        path.push_back(i);
        backtracking(n,k,i+1);
        path.pop_back();
    }
}



// 模板
// void backtracking(参数) {
//     if (终止条件) {
//         存放结果;
//         return;
//     }

//     for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
//         处理节点;
//         backtracking(路径，选择列表); // 递归
//         回溯，撤销处理结果
//     }
// }

