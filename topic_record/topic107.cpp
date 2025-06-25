#include<iostream>
#include<vector>
using namespace std;
vector<int> father;

void init(int n){
    father.resize(n+1);
    for (int i = 1; i <= n; i++){
        father[i] = i;
    }
}

int find(int x){
    return x == father[x] ? x : father[x] = find(father[x]);
}       // 路径压缩

bool isSame(int a, int b){
    a = find(a);
    b = find(b);
    return a == b;
}

void add(int a, int b){
    // if (find(a) != find(b)) father[b] = find(a);
    a = find(a);    // 注意一定要先回到根节点
    b = find(b);
    a == b ? :father[b] = a;
}

int main(){
    int m, n;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    int a, b;
    cin >> a >> b;
    isSame(a, b) ? cout << 1 : cout << 0;
    return 0;
}