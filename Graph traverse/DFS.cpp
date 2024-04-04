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
output:
1
2
4
5
3
6
*/
vector<int> v_node[100];
char color[100];

void DFS(int source){
    int u = source;
    color[source] = 'g';
    cout<<u<<endl;
    for(auto v : v_node[u]){
        if(color[v] == 'w')
            DFS(v);
    }
    color[u]='b';
}

int main(){
    int node,edge;
    cin>>node>>edge;

    for(int i=0;i<edge;i++){
        int a,b;
        cin>>a>>b;
        v_node[a].push_back(b);
        v_node[b].push_back(a);
    }

    for(int i=1;i<=node;i++)
        color[i]='w';
    int source;
    cout<<"insert source node"<<endl;
    cin>>source;
    cout<<"Path for DFS"<<endl;
    DFS(source);
    return 0;
}
