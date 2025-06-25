#include<vector>

using namespace std;

int n = 100005;
vector<int> father = vector<int>(n, 0);

void init(){
    for (int i = 0; i < n; i++){
        father[i] = i;
    }
}

int find(int u){        // 寻找根节点
    return u==father[u] ? u:(father[u] = find(father[u]));
}

bool isSame(int u, int v){      // 判断两个节点是否在同一个集合
    u = find(u);
    v = find(v);
    return u == v;
}

void join(int u, int v){        // 将两个节点接入到同一个集合
    u = find(u);
    v = find(v);
    if (u == v) return;
    father[v] = u;
}