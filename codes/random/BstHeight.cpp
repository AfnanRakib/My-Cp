#include <bits/stdc++.h>
using namespace std;
/*
Md.Rakib Hasan
ID: 20210204027

input:
6 5
1 2
1 3
2 4
2 5
3 6
1
output: Height is: 2
*/
vector<int> v_node[100];
int level[100];

int Height(int source){
    for(int i=0;i<100;i++){
        level[i]=-1;
    }
    queue<int> q;
    q.push(source);
    level[source]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v : v_node[u]){
            if(level[v]==-1){
                q.push(v);
                level[v]=level[u]+1;
            }
        }
    }
    int h=*max_element(level,level+100);
    return h;
}

int main(){
    int node,edge;
    cin>>node>>edge;

    for(int i=1;i<edge+1;i++){
        int a,b;
        cin>>a>>b;
        v_node[a].push_back(b);
        v_node[b].push_back(a);
    }
    int source;
    cout<<"insert source node"<<endl;
    cin>>source;
    cout<<"Height is: "<<Height(source);

    return 0;
}
