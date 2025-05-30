#include<iostream>      // 洛谷B3632
#include<queue>
#include<limits>
#include<vector>

using namespace std;

int solution(int n){
    queue<int> q;
    q.push(1);
    vector<int> list(n+1, numeric_limits<int>::max());
    list[0] = list[1]=  0;
    // int capacity = 1;
    // int steps = 1;
    while(list[n] == numeric_limits<int>::max()){
        while(!q.empty()){
            int node = q.front();
            int steps = list[node]+1;
            if(node-1 > 0 && list[node-1] > steps){
                list[node-1] = min(steps, list[node-1]);
                q.push(node-1);
            }
            if (node+1 <= n && list[node+1] > steps){
                list[node+1] = min(steps, list[node+1]);
                q.push(node+1);
            }
            if (node*2 <= n && list[node*2] > steps){
                list[node*2] = min(steps, list[node*2]);
                q.push(node*2);
            }
            q.pop();
        }
    } 
    if (list[n] == numeric_limits<int>::max()) return -1;
    return list[n];
}


int main(){
    int n;
    cin >> n;
    cout << solution(n);
    return 0;
}