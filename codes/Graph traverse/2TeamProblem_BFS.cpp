#include <bits/stdc++.h>
using namespace std;

/*

divide some people in two team named '1' &'2' where two friend cant be in same team.
two people is called friend if they are connected through an edge

input: first line have two integer node and edge. then edge line followed where each line have two adjacent node

5 3
1 2
1 3
4 5

output: output their team name in their node names increasing order. and print impossible if such task is not possible
for 1,2,3,4,5 node output is,

1 2 2 1 2

*/

int color[10000005];
vector<int> v_node[10000005];
int f=0;

void BFS(int source){
    queue<int> q;
    q.push(source);
    color[source]=0;
    while(!q.empty()){
        int u=q.front();

        q.pop();

        for(auto v:v_node[u]){
            if(color[v]==-1){
                color[v]=1-color[u];
                q.push(v);
            }
            else if(color[v]==color[u]){
                f=1;
                break;
            }
        }
    }
}

void traverse(int n){
    for(int i=1;i<n+1;i++){
        color[i]=-1;
    }
    for(int i=1;i<n+1;i++){
        if(f==1)
            return;
        if(color[i]==-1)
            BFS(i);
    }
    for(int i=1;i<n+1;i++){
        cout<<color[i]+1<<" ";
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=1;i<m+1;i++){
        int a,b;
        cin>>a>>b;
        v_node[a].push_back(b);
        v_node[b].push_back(a);
    }
    traverse(n);
    if(f==1)
        cout<<"impossible";

    return 0;
}
