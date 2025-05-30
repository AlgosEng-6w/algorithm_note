#include<iostream>
#include<vector>
using namespace std;

vector<int>father;

void init(int n){
    do {
        father[n] = n;
    }while(n--);        // 注意能否初始化到特殊节点
}

int find(int a){
    if (father[a] == a) return a;
    return father[a] = find(father[a]);
}

bool join(int a, int b){
    if (father[b] == b) {
        father[b] = a;
        return true;
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    father.resize(n+1);
    init(n);
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if (!join(a, b)) cout << a << " " << b;
    }
    return 0;
}