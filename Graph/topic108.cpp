#include<iostream>
#include<vector>

using namespace std;
vector<int> father;

void init(int n){
    while(n--) father[n] = n;
}
int find(int a){
    if (a == father[a]) return a;
    return father[a] = find(father[a]);
}

bool join(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return false;
    father[a] = b;
    return true;
}

int main(){
    int n;
    cin >> n;
    father.resize(n+1);
    init(n);
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if (!join(a, b)){
            cout << a << " " << b;
        }
    }
    return 0;
}