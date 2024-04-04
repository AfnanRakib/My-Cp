#include<bits/stdc++.h>
using namespace std;
/*
input:
6 9
1 2 1
2 4 2
4 6 1
1 3 5
3 5 2
5 6 2
2 3 2
2 5 1
4 5 3
1
output:
1) cost: 0 , Path: 1
2) cost: 1 , Path: 1->2
3) cost: 3 , Path: 1->2->3
4) cost: 3 , Path: 1->2->4
5) cost: 2 , Path: 1->2->5
6) cost: 4 , Path: 1->2->4->6

check negative edge fail: https://www.youtube.com/watch?v=R3g2SSlyY_0
*/
#define INF 1e5
priority_queue<pair<int, int>> q;
vector<pair<int,int> > g[1000];
vector<int> dist(1000,INF);
vector<int> p(1000,-1);\
set<int> s;

void go(int dest){
    if(p[dest]!=dest){
        go(p[dest]);
        cout<<"->";
    }
    cout<<dest;
}

void initialize_single_source(int n, int s)
{
    for(int i=0;i<n+1;i++){
        dist[i] = INF;
        p[i] = i;
    }
    dist[s] = 0;
}

void relax(int parent,int child,int weight){
    if(dist[parent]+weight < dist[child]){
        dist[child]=dist[parent]+weight;
        p[child]=parent;
        //if(!s.count(child))
            q.push(make_pair(dist[child],child));
    }
}

void dijkstra(int source,int node)
{
    initialize_single_source(node,source);
    q.push(make_pair(0, source));
    while(!q.empty())
    {
        auto u=q.top();
        q.pop();
        int parent=u.second;
        //s.insert(parent);
        for(auto v:g[parent]){
            int child=v.first;
            int weight=v.second;
            relax(parent,child,weight);
        }
    }
}

int main()
{
    int node,edge;
    cin>>node>>edge;
    cout<<"Source : Destination : Weight"<<endl;
    for(int i=0;i<edge;i++){
        int s, d, w;
        cin>>s>>d>>w;
        g[s].push_back(make_pair(d,w));
    }
    int source;
    cin>>source;
    dijkstra(source,node);
    for(int i=1;i<=node;i++){
        cout<<i<<") cost: "<<dist[i]<<" , Path: ";
        go(i);
        cout<<endl;
    }
//    for(auto &it:s){
//        cout<<it<<" ";
//    }
    return 0;
}

