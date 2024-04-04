#include <bits/stdc++.h>
using namespace std;

/*
10 13
1 2
1 3
1 4
2 6
6 10
4 7
3 7
3 8
9 10
9 7
8 7
8 5
10 5
*/
vector<int> v_node[100];
int level[15];
int parent[11];

void BFS(int source){
    for(int i=0;i<15;i++){
        level[i]=INT_MAX;
        parent[i]=i;
    }
    queue<int> q;
    q.push(source);
    level[source]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<v_node[u].size();i++){
            int v=v_node[u][i];
            if(level[v]==INT_MAX){
                q.push(v);
                level[v]=level[u]+1;
                parent[v]=u;
            }
        }
    }
}

void go(int dest){
    if(parent[dest]!=dest){
        go(parent[dest]);
        cout<<"->";
    }
    cout<<dest;
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
    cout<<"Adjacency list"<<endl;
    for(int i=1;i<node+1;i++){
        cout<<i<<" -> ";
        for(int j=0;j<v_node[i].size();j++){
            cout<<v_node[i][j]<<' ';
        }
        cout<<endl;
    }
    BFS(10);
    cout<<"Parents of all"<<endl;
    for(int i=1;i<node+1;i++){
        cout<<i<<": "<<parent[i]<<endl;
    }
    cout<<"levels of all"<<endl;
    for(int i=1;i<node+1;i++){
        cout<<i<<": "<<level[i]<<endl;
    }
    cout<<"Koi jaba?"<<endl;
    int dest;
    cin>>dest;
    go(dest);

    return 0;
}
