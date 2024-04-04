#include<bits/stdc++.h>
using namespace std;
/*
          2          19
   (1)--------(2)---------(3)
    | \        |         / |  \9
    |   \      |     17/   |   \
  8 |     \    |25   /     |    (4)
    |    14 \  |   /      5|    /
    |         \| /         |   /1
   (7)--------(6)----------(5)/
          21         13

7 11
1 2 2
2 3 19
3 4 9
4 5 1
5 6 13
6 7 21
7 1 8
1 6 14
2 6 25
3 6 17
3 5 5
1
T={(2,1),(3,5),(4,5),(5,6),(6,1),(7,1),}
Cost= 43
total edges= 6
          2
   (1)--------(2)
    | \                   (3)
    |   \                  |    (4)
  8 |     \                |    /
    |    14 \             5|   /1
    |         \            |  /
   (7)        (6)----------(5)
                     13
*/

#define INF 1e5
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q; //w,s
vector<pair<int,int>> graph[1000];//d,w
set<pair<int, int>> T;
int cost=0;
int weight[1000];
int parent[1000];
int visited[1000];

void initialize(int n)
{
    for(int i=1;i<=n;i++){
        weight[i]=INF;
        visited[i]=false;
        parent[i]=-1;
    }
}

void prims(int root,int n)
{
    initialize(n);
    weight[root]=0;
    Q.push({0,root});
    while(!Q.empty()){
        int s=Q.top().second;
        Q.pop();
        if(visited[s])
            continue;
        visited[s]=true;
        for(auto p:graph[s]){
            int d=p.first;
            int w=p.second;
            if(!visited[d] && weight[d]>w){
                parent[d]=s;
                weight[d]=w;
                Q.push({w,d});
            }
        }
    }
    for(int i=1;i<=n; i++){
        if(parent[i]!=-1){
            T.insert({i,parent[i]});
            cost+=weight[i];
        }
    }
}

int main()
{
    int node,edge,num=1;
    map<string,int> nodeNo;
    map<int,string> nodeName;
    cin>>node>>edge;
    cout<<"Source : Destination : Weight"<<endl;
    for(int i=0;i<edge;i++){
        string s, d;
        int w;
        cin>>s>>d>>w;
        if(!nodeNo.count(s)){
            nodeNo.insert({s,num});
            num++;
        }
        if(!nodeNo.count(d)){
            nodeNo.insert({d,num});
            num++;
        }
        graph[nodeNo[s]].push_back(make_pair(nodeNo[d],w));
        graph[nodeNo[d]].push_back(make_pair(nodeNo[s],w));
    }
    for(auto &it : nodeNo){
        nodeName[it.second]=it.first;
    }
    int root;
    cin>>root;
    prims(root,node);
    cout<<"T={";
    for(auto it:T){
        cout<<"("<<it.first<<","<<it.second<<"),";
    }
    cout<<"}"<<endl<<"Cost= "<<cost<<endl<<"total edges= "<<T.size()<<endl;
    return 0;
}

/*
8 10
1 2 3
1 8 14
2 3 8
2 8 10
3 6 2
3 4 15
5 6 9
6 7 4
6 8 5
8 7 6
4
T={(1,2),(2,3),(3,4),(5,6),(6,3),(7,6),(8,6),}
Cost= 46
total edges= 7
*/

